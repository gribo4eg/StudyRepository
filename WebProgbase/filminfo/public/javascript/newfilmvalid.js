
function validation(id) {
    var data = document.getElementById(id).value;

    var warning = 'warning';
    var status = false;
    var warnMess = " ";

    if (data.length === 0) {
        warnMess = firstToUpper(id) + ' field is required';
        document.getElementById(warning).innerHTML = warnMess;
        status = true;
    }

    else if (!status && id === "title" && (typeof(data) !== 'string' || data.length <= 2))
    {
        if (data.length < 3) warnMess = firstToUpper(id) + ' field too short';
        else warnMess = firstToUpper(id) + ' field must be a string';
        document.getElementById(warning).innerHTML = warnMess;
        status = true;
    }

    else if (!status && id === "genres" && (typeof(data) != 'string' || haveNumbers(data) || data.length <= 2))
    {
        if (data.length < 3) warnMess = firstToUpper(id) + ' field too short';
        else warnMess = firstToUpper(id) + ' field must be a string';
        document.getElementById(warning).innerHTML = warnMess;
        status = true;
    }

    else if (!status && id === "director" && (typeof(data) != 'string' || haveNumbers(data) || data.length <= 2))
    {
        if (data.length < 5) warnMess = firstToUpper(id) + ' field too short';
        else warnMess = firstToUpper(id) + ' field must be a string';
        document.getElementById(warning).innerHTML = warnMess;
        status = true;
    }

    else if (!status && id === "budget" && ((typeof(data) !== 'number' && !haveNumbers(data)) || (data <= 0 || data >500)))
    {
        if(data <= 0 || data > 500) warnMess = firstToUpper(id) + ' field has bad value';
        else warnMess = firstToUpper(id) + ' field must be a number';
        document.getElementById(warning).innerHTML = warnMess;
        status = true;
    }

    else if (!status && id === "duration" && ((typeof(data) !== 'number' && !haveNumbers(data)) || data <= 30))
    {
        if(data <= 0 || data > 500) warnMess = firstToUpper(id) + ' field has bad value';
        else warnMess = firstToUpper(id) + ' field must be a number';
        document.getElementById(warning).innerHTML = warnMess;
        status = true;
    }

    if (!status)
        document.getElementById(warning).innerHTML = warnMess;

    var result = true;
    var fields = ['title', 'genres', 'director', 'budget', 'duration'];
    for (var i = 0; i < fields.length; i++) {
        if (!check(fields[i])) {
            result = false;
            break;
        }
    }

    if(result) {
        document.getElementById("button").disabled = false;
    }
    else {
        document.getElementById("button").disabled = true;

    }
}

function firstToUpper(str){
    return str.slice(0,1).toUpperCase() + str.slice(1);
}

function haveNumbers(str) {
    var num = parseInt(str.replace(/\D+/g,""));
    if(num && 0!==num.length) return true;
    else false;

}

function check(id) {
    var data = document.getElementById(id).value;

    if(data.length === 0) return false;

    else if(id === "title" && (typeof(data) !== 'string' || data.length <= 2))
        return false;

    else if(id === "genres" && (typeof(data) != 'string' || haveNumbers(data) || data.length <= 2))
        return false;

    else if(id === "director" && (typeof(data) != 'string' || haveNumbers(data) || data.length <= 2))
        return false;

    else if(id === "budget" && ((typeof(data) !== 'number' && !haveNumbers(data)) || (data <= 0 || data >500)))
        return false;

    else if(id === "duration" && ((typeof(data) !== 'number' && !haveNumbers(data)) || data <= 30))
        return false;

    else
        return true;

}
