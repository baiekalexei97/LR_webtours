Action()
{

	web_url("webtours", 
		"URL=http://127.0.0.1:1080/webtours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);

	web_set_sockets_option("SSL_VERSION", "2&3");

	web_add_cookie("SRCHUID=V=2&GUID=FFCCADB5C69E4D6A949D8B53BF9ED160&dmnchg=1; DOMAIN=iecvlist.microsoft.com");

	web_add_cookie("SRCHD=AF=NOFORM; DOMAIN=iecvlist.microsoft.com");

	web_add_cookie("MC1=GUID=e01ca16ee9374d5f837a71f371bf3d68&HASH=e01c&LV=201907&V=4&LU=1563279668044; DOMAIN=iecvlist.microsoft.com");

	web_add_cookie("MUID=2E1EF33E72216C360622FEA576216AFE; DOMAIN=iecvlist.microsoft.com");

	web_add_cookie("SRCHUSR=DOB=20190711; DOMAIN=iecvlist.microsoft.com");

	web_add_header("UA-CPU", 
		"AMD64");

	web_url("iecompatviewlist.xml", 
		"URL=https://iecvlist.microsoft.com/IE11/1478281996/iecompatviewlist.xml", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/xml", 
		"Referer=", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(13);

	lr_start_transaction("UC1_TR01_Login");

	web_submit_data("login.pl", 
		"Action=http://127.0.0.1:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?in=home", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=userSession", "Value=127478.050789793zffHVfcpcDHfDQDtcpQVDtcf", ENDITEM, 
		"Name=username", "Value=Jojo", ENDITEM, 
		"Name=password", "Value=bean", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=login.x", "Value=49", ENDITEM, 
		"Name=login.y", "Value=14", ENDITEM, 
		LAST);

	lr_end_transaction("UC1_TR01_Login",LR_AUTO);

	lr_think_time(34);

	lr_start_transaction("UC01_TR02_CheckTickets");

	web_url("Itinerary Button", 
		"URL=http://127.0.0.1:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC01_TR02_CheckTickets",LR_AUTO);

	lr_think_time(38);

	lr_start_transaction("UC01_TR03_CancelFlight");

	web_submit_data("itinerary.pl", 
		"Action=http://127.0.0.1:1080/cgi-bin/itinerary.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/itinerary.pl", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=flightID", "Value=2514660040-7777-JB", ENDITEM, 
		"Name=flightID", "Value=251448903-1568-JB", ENDITEM, 
		"Name=flightID", "Value=251453108-2378-JB", ENDITEM, 
		"Name=flightID", "Value=251479303-3091-JB", ENDITEM, 
		"Name=5", "Value=on", ENDITEM, 
		"Name=flightID", "Value=251476072-3919-JB", ENDITEM, 
		"Name=.cgifields", "Value=4", ENDITEM, 
		"Name=.cgifields", "Value=1", ENDITEM, 
		"Name=.cgifields", "Value=3", ENDITEM, 
		"Name=.cgifields", "Value=2", ENDITEM, 
		"Name=.cgifields", "Value=5", ENDITEM, 
		"Name=removeFlights.x", "Value=36", ENDITEM, 
		"Name=removeFlights.y", "Value=8", ENDITEM, 
		LAST);

	lr_end_transaction("UC01_TR03_CancelFlight",LR_AUTO);

	lr_think_time(24);

	lr_start_transaction("UC01_TR04_logout");

	web_url("SignOff Button", 
		"URL=http://127.0.0.1:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC01_TR04_logout",LR_AUTO);

	return 0;
}