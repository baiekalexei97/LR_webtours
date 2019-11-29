vuser_end()
{
	lr_start_transaction("UC01_TR04_logout");

	web_url("SignOff Button", 
		"URL=http://{Host}:{Port}/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{Host}:{Port}/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC01_TR04_logout",LR_AUTO);

	return 0;
}
