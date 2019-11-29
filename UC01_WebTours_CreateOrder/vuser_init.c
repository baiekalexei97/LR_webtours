vuser_init()
{
	
	web_reg_save_param("userSession1",
	                   "LB=hidden\" name\=\"userSession\" value\=\"",
	                   "RB=\"/>",
	                   LAST);

	web_url("webtours", 
		"URL=http://{Host}:{Port}/webtours/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	web_set_sockets_option("SSL_VERSION", "2&3");

	web_add_header("UA-CPU",
		"AMD64");

	lr_think_time(5);

	lr_start_transaction("UC01_TR01_Login");

	web_reg_find("Text=, to the Web Tours reservation pages.", 
	             LAST);
		
	web_submit_data("login.pl", 
		"Action=http://{Host}:{Port}/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://{Host}:{Port}/cgi-bin/nav.pl?in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=userSession", "Value={userSession1}", ENDITEM, 
		"Name=username", "Value={Login}", ENDITEM, 
		"Name=password", "Value={Password}", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=login.x", "Value=45", ENDITEM, 
		"Name=login.y", "Value=13", ENDITEM, 
		LAST);

	lr_end_transaction("UC01_TR01_Login",LR_AUTO);
	return 0;
}
