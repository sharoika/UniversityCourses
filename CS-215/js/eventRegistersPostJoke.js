function viewcount()
{
    var input = document.getElementById("countInput");
    input.innerHTML = "";
    var title = document.getElementById("jokeTitle").value;
    var length = title.length;
    var togo = 50 - length;
    if (length > 50)
    {
        var p1 = document.createElement('p');
        var top = document.createTextNode("Letter Count: " + length);
        p1.appendChild(top);
        var p2 = document.createElement('p');
        p2.classList.add('red');
        var bottom = document.createTextNode("LETTER LIMIT REACHED");
        p2.appendChild(bottom);
        input.appendChild(p1);
        input.appendChild(p2);
    }
    else
    {
        var p1 = document.createElement('p');
        var top = document.createTextNode("Letter Count: " + length);
        p1.appendChild(top);
        var p2 = document.createElement('p');
        var bottom = document.createTextNode("Remaining: " + togo);
        p2.appendChild(bottom);
        input.appendChild(p1);
        input.appendChild(p2);
    }
}


document.addEventListener('keyup', (event) => {
    viewcount();
});