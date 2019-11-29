Order()
{
	lr_param_sprintf("flightVal", lr_paramarr_random("OutboundFlight"));

	lr_think_time(5);
	
	web_reg_find("Text=Total for 1 ticket(s) is \= $",
	             LAST);

	lr_start_transaction("UC01_TR04_Select_Flight");

	web_submit_data("reservations.pl_2", 
		"Action=http://{Host}:{Port}/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://{Host}:{Port}/cgi-bin/reservations.pl", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=outboundFlight", "Value={flightVal}", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=seatType", "Value=Business", ENDITEM, 
		"Name=seatPref", "Value=Window", ENDITEM, 
		"Name=reserveFlights.x", "Value=36", ENDITEM, 
		"Name=reserveFlights.y", "Value=3", ENDITEM, 
		LAST);

	lr_end_transaction("UC01_TR04_Select_Flight",LR_AUTO);
	
	web_reg_find("Text=<font color\=\"white\"><b>JojoBean's Flight Invoice</b></font>",
	             LAST);

	lr_start_transaction("UC01_TR05_Payment_Details");

	lr_think_time(5);

	web_submit_data("reservations.pl_3", 
		"Action=http://{Host}:{Port}/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://{Host}:{Port}/cgi-bin/reservations.pl", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=firstName", "Value={FirstName}", ENDITEM, 
		"Name=lastName", "Value={LastName}", ENDITEM, 
		"Name=address1", "Value={Address1}", ENDITEM, 
		"Name=address2", "Value={Address2}", ENDITEM, 
		"Name=pass1", "Value={FirstName} {LastName}", ENDITEM, 
		"Name=creditCard", "Value={CardNum}", ENDITEM, 
		"Name=expDate", "Value={ExpDate}", ENDITEM, 
		"Name=oldCCOption", "Value=", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatType", "Value=Business", ENDITEM, 
		"Name=seatPref", "Value=Window", ENDITEM, 
		"Name=outboundFlight", "Value={flightVal}", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=returnFlight", "Value=", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=.cgifields", "Value=saveCC", ENDITEM, 
		"Name=buyFlights.x", "Value=61", ENDITEM, 
		"Name=buyFlights.y", "Value=15", ENDITEM, 
		EXTRARES, 
		LAST);

	lr_end_transaction("UC01_TR05_Payment_Details",LR_AUTO);

	lr_think_time(5);
	
	web_reg_find("Text='s Flight Transaction Summary</B></color></TD></TR>",
	             LAST);

	lr_start_transaction("UC01_TR06_Itinerary");

	web_url("Itinerary Button", 
		"URL=http://{Host}:{Port}/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{Host}:{Port}/cgi-bin/nav.pl?page=menu&in=flights", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC01_TR06_Itinerary",LR_AUTO);


	return 0;
}