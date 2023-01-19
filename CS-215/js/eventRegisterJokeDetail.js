
refreshrating((document.getElementById("rating_input").value), (document.getElementById("average_rating").innerHTML));

var increase = document.getElementById("increase_button");
increase.addEventListener("click", increase_clicked);

var decrease = document.getElementById("decrease_button");
decrease.addEventListener("click", decrease_clicked);