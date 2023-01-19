var uname = document.getElementById("signupUsername");
var email = document.getElementById("signupEmail");
var pwd = document.getElementById("signupPassword");
var cpwd = document.getElementById("signupConfirmPassword");
var dob = document.getElementById("signupDOB");
var avatar = document.getElementById("profilephoto");

uname.addEventListener("blur", usernameHandler);
pwd.addEventListener("blur", pwdHandler);
cpwd.addEventListener("blur", cpwdHandler);
dob.addEventListener("blur", dobHandler);
avatar.addEventListener("blur", avatarHandler);
email.addEventListener("blur", emailHandler);