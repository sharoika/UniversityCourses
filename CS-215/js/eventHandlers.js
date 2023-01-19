function emailHandler(event) {
	let email = event.target;
	if (!validateEmail(email.value)) {
		document.getElementById(email.id).classList.add("input-error");
		document.getElementById("error-text-" + email.id).classList.remove("hidden");
	}
	else {
		document.getElementById(email.id).classList.remove("input-error");
		document.getElementById("error-text-" + email.id).classList.add("hidden");
	}
}

function usernameHandler(event) {
	let uname = event.target;
	if (!validateUsername(uname.value)) {
		document.getElementById(uname.id).classList.add("input-error");
		document.getElementById("error-text-" + uname.id).classList.remove("hidden");
	}
	else {
		document.getElementById(uname.id).classList.remove("input-error");
		document.getElementById("error-text-" + uname.id).classList.add("hidden");
	}
}

function pwdHandler(event) {
	let pwd = event.target;
	if (pwd.value.length !== 8) {
		document.getElementById(pwd.id).classList.add("input-error");
		document.getElementById("error-text-" + pwd.id).classList.remove("hidden");
	}
	else {
		document.getElementById(pwd.id).classList.remove("input-error");
		document.getElementById("error-text-" + pwd.id).classList.add("hidden");
	}
}

function cpwdHandler(event) {
	let pwd = document.getElementById("signupPassword");
	let cpwd = event.target;
	if (pwd.value !== cpwd.value) {
		document.getElementById(cpwd.id).classList.add("input-error");
		document.getElementById("error-text-" + cpwd.id).classList.remove("hidden");
	}
	else {
		document.getElementById(cpwd.id).classList.remove("input-error");
		document.getElementById("error-text-" + cpwd.id).classList.add("hidden");
	}
}

function dobHandler(event) {
	let dob = event.target;
	if (!validateDOB(dob.value)) {
		document.getElementById(dob.id).classList.add("input-error");
		document.getElementById("error-text-" + dob.id).classList.remove("hidden");
	}
	else {
		document.getElementById(dob.id).classList.remove("input-error");
		document.getElementById("error-text-" + dob.id).classList.add("hidden");
	}
}

function avatarHandler(event) {
	let avatar = event.target;
	if (!validateAvatar(avatar.value)) {
			document.getElementById(avatar.id).classList.add("input-error");
			document.getElementById("error-text-" + avatar.id).classList.remove("hidden");
		}
		else {
			document.getElementById(avatar.id).classList.remove("input-error");
			document.getElementById("error-text-" + avatar.id).classList.add("hidden");
		}
}

function validateEmail(email) {
	let emailRegEx = /^(([^<>()[\]\\.,;:\s@"]+(\.[^<>()[\]\\.,;:\s@"]+)*)|(".+"))@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\])|(([a-zA-Z\-0-9]+\.)+[a-zA-Z]{2,}))$/;
	if (emailRegEx.test(email))
	{
		return true;
	}
	else
	{
		return false;
	}
}

function validateDOB(dob) {
	let dobRegEx = /^\d{4}[-]\d{2}[-]\d{2}$/;

	if (dobRegEx.test(dob))
		return true;
	else
		return false;
}

function validateAvatar(avatar) {

	let avatarRegEx = /^[^\n]+.[a-zA-Z]{3,4}$/;

	if (avatarRegEx.test(avatar))
		return true;
	else
		return false;
}

function validateUsername(uname) {

	let unameRegEx = /^[a-zA-Z0-9_]+$/;
	if (unameRegEx.test(uname))
		return true;
	else
		return false;
}

function refreshrating(inputrating, inputaverage)
{
	rating = inputrating;
	average = inputaverage;

	var average_location = document.getElementById("average_rating");
	average_location.innerHTML = "";
	average_location.innerHTML = average;
	
    var location = document.getElementById("rating_location");
    location.innerHTML = "";

    var div1 = document.createElement("div");
    var decrease = document.createElement("button");

    if (rating > 0 || rating == "N/A")
    {
        decrease.textContent = "decrease";
        decrease.classList.add('rating_button');
		decrease.id = "decrease_button";
        div1.appendChild(decrease);
    }
    else
    {
        decrease.textContent = "decrease";
        decrease.classList.add('rating_button_hidden');
		decrease.id = "decrease_button";
        div1.appendChild(decrease);
    }

    var input = document.createElement("input");
    input.id = "rating_input";
    input.name = "rating_input";
    input.value = rating;
    input.setAttribute('type', 'text');
    div1.appendChild(input);
    var increase = document.createElement("button");

    if (rating < 5 || rating == "N/A")
    {
        increase.classList.add('rating_button');
        increase.textContent = "increase";
		increase.id = "increase_button";
        div1.appendChild(increase);
    }
    else
    {
        increase.classList.add('rating_button_hidden');
        increase.textContent = "increase";
		increase.id = "increase_button";
        div1.appendChild(increase);
    }

    var div2 = document.createElement("div");
    location.appendChild(div1);
    location.appendChild(div2);
	
	var increase = document.getElementById("increase_button");
	increase.addEventListener("click", increase_clicked);

	var decrease = document.getElementById("decrease_button");
	decrease.addEventListener("click", decrease_clicked);
}

function increase_clicked(event) {
	console.log("increasing rating");
	var rating = document.getElementById("rating_input").value;
	if (rating == "N/A")
    {
        rating = 0;
    }
    else
    {
        rating = Math.round(parseInt(rating)  + 1);
    }
	let xhr = new XMLHttpRequest();
	xhr.onreadystatechange = function () {
		if (xhr.readyState == 4 && xhr.status == 200) {

			object = JSON.parse(xhr.responseText);
			refreshrating(object.rating, parseFloat(object.avgRating).toFixed(2));
			}
		}
		xhr.open("GET","ajax_backend_A.php?rating="+rating, true);
		xhr.send();
}

function decrease_clicked(event) {
	console.log("decreasing rating");
	var rating = document.getElementById("rating_input").value;
    if (rating == "N/A")
    {
        rating = 5;
    }
    else
    {
        rating = Math.round(parseInt(rating) - 1);
    }
	let xhr = new XMLHttpRequest();
	xhr.onreadystatechange = function () {
		if (xhr.readyState == 4 && xhr.status == 200) {

			object = JSON.parse(xhr.responseText);
			refreshrating(object.rating, parseFloat(object.avgRating).toFixed(2));
			}
		}
		xhr.open("GET","ajax_backend_A.php?rating="+rating, true);
		xhr.send();
}

function updateAverage(event)
{
	console.log("refreshing joke ratings");
	var start = (document.getElementById("jID").value);
	var i = start; 
	loop(i, start);
}

function loop(i, start)
{
	if (i > (start-20) && i > 0)
	{
		var item = document.getElementById("jID"+i)
		if (item.value == null)
		{
			item.value = 0.00;
		}
		let xhr = new XMLHttpRequest();
		xhr.onreadystatechange = function () {
			if (xhr.readyState == 4 && xhr.status == 200) {
				object = JSON.parse(xhr.responseText);
				var change = document.getElementById("average_rating_"+item.value)
				if (isNaN(object.avgRating) || object.avgRating == null)
				{
					change.innerHTML = "Average Rating: 0.00";
				}
				else
				{
					change.innerHTML = "Average Rating: "+parseFloat(object.avgRating).toFixed(2);
				}
				loop(i-1, start);
				}
			}
		xhr.open("GET","ajax_backend_B.php?jid="+item.value, true);
		xhr.send();
	}
	else 
	{
		return;
	}
}

function updateList(event)
{
	console.log("refreshing joke list");
	var start = (document.getElementById("jID").value);
	let xhr = new XMLHttpRequest();
	xhr.onreadystatechange = function () {
		if (xhr.readyState == 4 && xhr.status == 200) {
			object = JSON.parse(xhr.responseText);
			if ((start + object.length) > 20)
			{
				if (object.length > 0)
				{
				deleteJokes((start-20+object.length), (start-20));
				}
			}
			for (var i = 0; i < object.length; i++)
			{
				addJoke(object[i]);
			}
			start = (document.getElementById("jID").value);
			}
		}
	xhr.open("GET","ajax_backend_C.php?jid="+(start), true);
	xhr.send();
}

function addJoke(object)
{
	var location = document.getElementById("jokes");

	var form = document.createElement("form");
	form.name = object.jID;
	form.method = "post";
	form.classList = "auth-form";
	form.id = "details"+object.jID;

	var input1 = document.createElement("input");
	input1.type = "hidden";
	input1.value = object.jID;
	input1.id = "jID";
	input1.name = object.jID;

	var input2 = document.createElement("input");
	input2.type = "hidden";
	input2.id = "jID"+object.jID;
	input2.name = "jID";
	input2.value = object.jID;

	var jokediv = document.createElement("div");
	jokediv.classList = "joke";
	jokediv.onclick = form.submit();

	// joke top
	var joketop = document.createElement("div");
	joketop.classList = "joke-top-row";

	// in-line left
	var top_inlineleft = document.createElement("div");
	top_inlineleft.classList = "inline-left";

	var h3_top_inlineleft = document.createElement("h3");
	h3_top_inlineleft.innerHTML = object.title;

	top_inlineleft.appendChild(h3_top_inlineleft);
	joketop.appendChild(top_inlineleft);

	// in-line right
	var top_inlineright = document.createElement("div");
	top_inlineright.classList = "inline-right";

	var h4_top_inlineright = document.createElement("h4");
	h4_top_inlineright.classList = "inline";
	h4_top_inlineright.innerHTML = "By: " + object.username;

	var img_top_inlineright = document.createElement("img");
	img_top_inlineright.classList = "small-profile-logo";
	img_top_inlineright.src = "uploads/"+object.avatar_url;

	top_inlineright.appendChild(h4_top_inlineright);
	top_inlineright.appendChild(img_top_inlineright);
	joketop.appendChild(top_inlineright);

	// adding top to joke div
	jokediv.appendChild(joketop);

	// making breaks in joke div
	var break1 = document.createElement('br');
	var break2 = document.createElement('br');

	jokediv.appendChild(break1);
	jokediv.appendChild(break2);

	// adding the second top row
	var joketoprow = document.createElement('div');
	joketoprow.classList = "joke-top-row";
	
	var joketoprow_inlineright = document.createElement('div');
	joketoprow_inlineright.classList = "inline-right";

	var averageRatingHeading = document.createElement("h4");
    averageRatingHeading.id = "average_rating_"+object.jID;

	if (isNaN(object.avgRating) || object.avgRating == null)
	{
		averageRatingHeading.innerHTML = "Average Rating: 0.00";
	}
	else
	{
		averageRatingHeading.innerHTML = "Average Rating: "+(object.avgRating);
	}

	joketoprow_inlineright.appendChild(averageRatingHeading);
	joketoprow.appendChild(joketoprow_inlineright);

	jokediv.appendChild(joketoprow);

	var break3 = document.createElement('br');
	jokediv.appendChild(break3);

	// adding the two bottom rows

    var jokeBottomRow = document.createElement("div");
    jokeBottomRow.classList = "joke-botton-row";

    var jokeP = document.createElement("p");
    jokeP.classList = "joke-p";
	jokeP.innerHTML = object.text;

	jokeBottomRow.appendChild(jokeP);

    var jokeBottomRow2 = document.createElement("div");
    jokeBottomRow2.classList = "joke-botton-row";

    var jokeB = document.createElement("b");
    jokeB.classList = "joke-p";
	jokeB.innerHTML = object.created_DT;

	jokeBottomRow2.appendChild(jokeB);

	jokediv.appendChild(jokeBottomRow);
	jokediv.appendChild(jokeBottomRow2);
	
	form.appendChild(jokediv);
	form.appendChild(input2);
	form.appendChild(input1);

	location.insertBefore(form, location.firstChild);

	jokediv.onclick = function(){form.submit()};
}

function deleteJokes(start, end)
{
	for (var i = start; i < end+2; i++)
	{
		deleted = document.getElementById("details"+i);
		deleted.remove();
	}
}