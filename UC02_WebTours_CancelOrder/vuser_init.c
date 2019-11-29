vuser_init()
{
		
	web_reg_save_param("userSession1",
	                  "LB=userSession\" value=\"",
	                 "RB=\"/>",
	                LAST);
	
	web_url("webtours", 
		"URL=http://{Host}:{Port}/webtours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		LAST);

	lr_think_time(10);

	lr_start_transaction("UC1_TR01_Login");

	web_submit_data("login.pl", 
		"Action=http://{Host}:{Port}/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://{Host}:{Port}/cgi-bin/nav.pl?in=home", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=userSession", "Value={userSession1}", ENDITEM, 
		"Name=username", "Value={Login}", ENDITEM, 
		"Name=password", "Value={Password}", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=login.x", "Value=49", ENDITEM, 
		"Name=login.y", "Value=14", ENDITEM, 
		LAST);

	lr_end_transaction("UC1_TR01_Login",LR_AUTO);

	return 0;
}
