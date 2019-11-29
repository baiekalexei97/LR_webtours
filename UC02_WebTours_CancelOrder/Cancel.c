Cancel()
{	
	int i = 1;
	lr_think_time(10);
	
	web_reg_save_param("flightIdArr",
	                  "LB=lightID\" value=\"",
	                  "RB=\"  />",
	                  "Ord=All",
	                  LAST);

	lr_start_transaction("UC01_TR02_CheckTickets");

	web_url("Itinerary Button", 
		"URL=http://{Host}:{Port}/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{Host}:{Port}/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC01_TR02_CheckTickets",LR_AUTO);

	lr_think_time(10);
	
	lr_save_string("1=on&", "Body");
	do{
		lr_save_string(lr_paramarr_idx("flightIdArr",i),"flightId");
		lr_save_int(i,".cgifields");
		lr_save_string(lr_eval_string("{Body}flightID={flightId}&.cgifields={.cgifields}&"),"Body");
		i++;
	}while(i <= atoi(lr_eval_string("{flightIdArr_count}")));
	
	lr_save_string(lr_eval_string("{Body}removeFlights.x=36&removeFlights.y=8"),"Body");

	lr_start_transaction("UC01_TR03_CancelFlight");

	web_custom_request("itinerary.pl", 
		"URL=http://{Host}:{Port}/cgi-bin/itinerary.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://{Host}:{Port}/cgi-bin/itinerary.pl", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		"Body={Body}",
		LAST);

	lr_end_transaction("UC01_TR03_CancelFlight",LR_AUTO);

	lr_think_time(10);

	return 0;
}