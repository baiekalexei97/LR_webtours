Search(){
	char * City1;
	char * City2;
	
	lr_think_time(5);
	
	web_reg_find("Text=>No. of Passengers : </td> <td>",
	             LAST);
	
	
	web_reg_save_param("Cities",	                   
	                   "LB=\">",
	                   "RB=</option>",
	                   "Ord=All",
	                   LAST
	);
	
	lr_start_transaction("UC01_TR02_Flights");

	web_url("Search Flights Button", 
		"URL=http://{Host}:{Port}/cgi-bin/welcome.pl?page=search", 
		"TargetFrame=body", 
		"Resource=0",		
		"RecContentType=text/html", 
		"Referer=http://{Host}:{Port}/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC01_TR02_Flights",LR_AUTO);
		
	City1 = lr_paramarr_random("Cities");
	City2 = lr_paramarr_random("Cities");
	
	while(strcmp(City1,City2) == 0){
		City2 = lr_paramarr_random("Cities");
	};
	lr_param_sprintf("City1",City1);
	lr_param_sprintf("City2",City2);
	
	lr_think_time(5);
	
	web_reg_find("Text=Flight departing from <B>",
	             LAST);
	
	web_reg_save_param("OutboundFlight",
	                   "LB=outboundFlight\" value\=\"",
	                   "RB=\"",
	                   "Ord=All",
	                   LAST);
	
	lr_start_transaction("UC01_TR03_Find_Flight");

	web_submit_data("reservations.pl", 
		"Action=http://{Host}:{Port}/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://{Host}:{Port}/cgi-bin/reservations.pl?page=welcome", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=depart", "Value={City1}", ENDITEM, 
		"Name=departDate", "Value=11/12/2019", ENDITEM, 
		"Name=arrive", "Value={City2}", ENDITEM, 
		"Name=returnDate", "Value=11/13/2019", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatPref", "Value=Window", ENDITEM, 
		"Name=seatType", "Value=Business", ENDITEM, 
		"Name=.cgifields", "Value=roundtrip", ENDITEM, 
		"Name=.cgifields", "Value=seatType", ENDITEM, 
		"Name=.cgifields", "Value=seatPref", ENDITEM, 
		"Name=findFlights.x", "Value=55", ENDITEM, 
		"Name=findFlights.y", "Value=6", ENDITEM, 
		LAST);

	lr_end_transaction("UC01_TR03_Find_Flight",LR_AUTO);
	return 0;
}
