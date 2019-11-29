vuser_end()
{		
	web_reg_find("Text=If you haven't registered yet, <A href\=\"/cgi-bin/login.pl?username\=&amp;password\=&amp;getInfo\=true\" ><B>sign up now",
	             LAST);
	
	lr_start_transaction("UC01_TR07_Logout");

	web_url("SignOff Button", 
		"URL=http://{Host}:{Port}/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://{Host}:{Port}/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("UC01_TR07_Logout",LR_AUTO);
	return 0;
}
