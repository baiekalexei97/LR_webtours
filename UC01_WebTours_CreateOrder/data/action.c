Action()
{

	web_url("webtours", 
		"URL=http://127.0.0.1:1080/webtours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
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
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(442);

	lr_start_transaction("UC01_TR01_Login");

	web_submit_data("login.pl", 
		"Action=http://127.0.0.1:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=userSession", "Value=127457.361036857zffzAiipAAiDDDDDDQDDzpfciAf", ENDITEM, 
		"Name=username", "Value=Jojo", ENDITEM, 
		"Name=password", "Value=bean", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=login.x", "Value=45", ENDITEM, 
		"Name=login.y", "Value=13", ENDITEM, 
		LAST);

	lr_end_transaction("UC01_TR01_Login",LR_AUTO);

	lr_think_time(86);

	lr_start_transaction("UC01_TR02_Flights");

	web_url("Search Flights Button", 
		"URL=http://127.0.0.1:1080/cgi-bin/welcome.pl?page=search", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC01_TR02_Flights",LR_AUTO);

	lr_think_time(525);

	lr_start_transaction("UC01_TR03_Find_Flight");

	web_submit_data("reservations.pl", 
		"Action=http://127.0.0.1:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/reservations.pl?page=welcome", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=depart", "Value=Los Angeles", ENDITEM, 
		"Name=departDate", "Value=11/12/2019", ENDITEM, 
		"Name=arrive", "Value=Paris", ENDITEM, 
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

	lr_think_time(274);

	lr_start_transaction("UC01_TR04_Select_Flight");

	web_submit_data("reservations.pl_2", 
		"Action=http://127.0.0.1:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/reservations.pl", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=outboundFlight", "Value=342;601;11/12/2019", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=seatType", "Value=Business", ENDITEM, 
		"Name=seatPref", "Value=Window", ENDITEM, 
		"Name=reserveFlights.x", "Value=36", ENDITEM, 
		"Name=reserveFlights.y", "Value=3", ENDITEM, 
		LAST);

	lr_end_transaction("UC01_TR04_Select_Flight",LR_AUTO);

	lr_start_transaction("UC01_TR05_Payment_Details");

	web_add_cookie("SRCHUID=V=2&GUID=FFCCADB5C69E4D6A949D8B53BF9ED160&dmnchg=1; DOMAIN=c.urs.microsoft.com");

	web_add_cookie("SRCHD=AF=NOFORM; DOMAIN=c.urs.microsoft.com");

	web_add_cookie("MC1=GUID=e01ca16ee9374d5f837a71f371bf3d68&HASH=e01c&LV=201907&V=4&LU=1563279668044; DOMAIN=c.urs.microsoft.com");

	web_add_cookie("MUID=2E1EF33E72216C360622FEA576216AFE; DOMAIN=c.urs.microsoft.com");

	web_add_cookie("SRCHUSR=DOB=20190711; DOMAIN=c.urs.microsoft.com");

	lr_think_time(97);

	web_submit_data("reservations.pl_3", 
		"Action=http://127.0.0.1:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/reservations.pl", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=firstName", "Value=Jojo", ENDITEM, 
		"Name=lastName", "Value=Bean", ENDITEM, 
		"Name=address1", "Value=Lenina", ENDITEM, 
		"Name=address2", "Value=Moscow", ENDITEM, 
		"Name=pass1", "Value=Jojo Bean", ENDITEM, 
		"Name=creditCard", "Value=123456789", ENDITEM, 
		"Name=expDate", "Value=08/23", ENDITEM, 
		"Name=oldCCOption", "Value=", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatType", "Value=Business", ENDITEM, 
		"Name=seatPref", "Value=Window", ENDITEM, 
		"Name=outboundFlight", "Value=342;601;11/12/2019", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=returnFlight", "Value=", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=.cgifields", "Value=saveCC", ENDITEM, 
		"Name=buyFlights.x", "Value=61", ENDITEM, 
		"Name=buyFlights.y", "Value=15", ENDITEM, 
		EXTRARES, 
		"Url=https://c.urs.microsoft.com/l1.dat?cw=637090496398164110&v=3&cv=9.11.17763.0&os=10.0.17763.0.0&pg=4A72F430-B40C-4D36-A068-CE33ADA5ADF9", "Referer=", ENDITEM, 
		LAST);

	lr_end_transaction("UC01_TR05_Payment_Details",LR_AUTO);

	lr_think_time(128);

	lr_start_transaction("UC01_TR06_Itinerary");

	web_url("Itinerary Button", 
		"URL=http://127.0.0.1:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?page=menu&in=flights", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC01_TR06_Itinerary",LR_AUTO);

	lr_think_time(52);

	lr_start_transaction("UC01_TR07_Logout");

	web_url("SignOff Button", 
		"URL=http://127.0.0.1:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://127.0.0.1:1080/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC01_TR07_Logout",LR_AUTO);

	return 0;
}