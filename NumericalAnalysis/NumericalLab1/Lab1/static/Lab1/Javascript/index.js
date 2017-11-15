$(document).ready(function () {
    checkFieldsEq();
    checkFieldFunc();

    $('#epsilonEq').keyup(checkFieldsEq);
    $('.intBorder, #epsilonFunc').keyup(checkFieldFunc);

    $('input[value="1"]').prop('checked', true);
    $('#selectMethod').val('bisection');
    $("option[value='hybrid']").prop('disabled', true);
    $("option[value='iteration']").prop('disabled', true);
});

function addStep(step) {
    $('#lobachevskyStepsTable').append(Mustache.render(lobachevskyStepTemplate, step));
}

function addAnalysis(analysis) {
    $('#rootsAnalysisTable').append(Mustache.render(analysisTemplate, analysis))
}

function addRootsL(roots) {
    $('#lobachevskyRootsTable').append(Mustache.render(standartTemplate, roots))
}

function addRootsN(roots) {
    $('#newtonRootsTable').append(Mustache.render(standartTemplate, roots))
}

function addFunctionStep(step) {
    $('#functionsRootTable').append(Mustache.render(standartTemplate, step))
}

function renderFuncAlert(alert) {
    $('#funcAlert').html(Mustache.render(alertTemplate, alert))
}

function renderLobachevskyAlert(alert) {
    $('#lobachevskyAlert').html(Mustache.render(alertTemplate,alert))
}

function hideErrors() {
    $('#funcAlert, #lobachevskyAlert').children().remove()
}

var equationPlotStatus = [];

$('#calcEq').on('click', function () {

    var n = 0;
    var nums = [];
    $($('.x').get().reverse()).each(function (i) {
        $this = $(this);
        nums.push($this.val());
        if ($this.val() !== '') {
            n = 1 + i;
        }
    });

    var data = {
        values : nums,
        epsilon : $('#epsilonEq').val(),
        n : n-1
    };
    console.log(data);
    $.ajax({
        type:'post',
        url:'/api/calc_lobachevsky/',
        contentType:'application/json',
        data:JSON.stringify(data),
        dataType:'json',
        success:function (result) {
            rootArr = result.roots.rootsL.slice();
            tmp = rootArr.splice(0, data.n);
            left = Math.min.apply(Math, tmp);
            right = Math.max.apply(Math,tmp);
            if (nums.toString() !== equationPlotStatus.toString())
                buildPlot('equationPlot',
                    formFuncOptions(null, left, right, nums, data.n),
                    null,nums);
            if (result.err) {
                var error = { message:result.err };
                renderLobachevskyAlert(error)
            }
            else {
                hideErrors();
                $('.lobachevskyTable').show();
                $('.lobachevskyResultsTable').children().remove();
                $.each(result.steps, function (i, obj) {
                    addStep(obj)
                });
                addAnalysis(result.analysis.negative.concat(result.analysis.positive));
                addRootsL(result.roots.rootsL);
                addRootsN(result.roots.rootsN);
            }
        },
        error: function () {
            alert("Error while posting data!")
        }
    });
});

var funcPlotStatus;

$('#calcFunc').on('click', function () {
    var borders = [];

    $('.intBorder').each(function () {
        borders.push(parseFloat($(this).val()))
    });

    if (borders[0] > borders[1]) borders[0] = [borders[1], borders[1] = borders[0]][0];

    var data = {
        function: $('input[name="function"]:checked').val(),
        method: $('#selectMethod').val(),
        interval: borders,
        epsilon: $('#epsilonFunc').val()
    };
    $.ajax({
        type:'post',
        url:'/api/calc_function/',
        contentType:'application/json',
        data:JSON.stringify(data),
        dataType:'json',
        success:function (result) {
            if (funcPlotStatus !== data.function) {
                buildPlot('funcPlot', formFuncOptions(data.function), data.function);
            }
            if (result.err) {
                var error = {message:result.err};
                renderFuncAlert(error)
            }
            else {
                hideErrors();
                $(".functionsTable").show();
                $('#functionsRootTable').children().remove();
                buildPlot('rootPlot', result.rootPlot);
                buildPlot('taskPlot',result.taskPlot);

                $.each(result.answer.steps, function (i, obj) {
                    addFunctionStep(obj)
                });
            }
        },
        error: function (xhr) {
            alert(xhr.responseText)
        }
    });
});

function formFuncOptions(func, left, right, numbers, n) {
    var f, a=-6.5, b=6.5, step=0.0001,
        x = [], y = [];
    if (func === '1')
        f = function (x) {
            return 1 + Math.pow(x,7) - Math.log(1 + Math.PI * Math.cos(Math.pow(x,3)))
                + Math.pow(x,10) - Math.pow(Math.tan(x),5) + x
        };
    else if (func === '2')
        f = function (x) {
            return Math.sqrt(Math.abs(x)) - 9 * Math.pow(x,2) + 23 - Math.sin(x)
        };
    else {
        a = left && left < a ? left - 1 : a;
        b = right && right > b ? right + 1 : b;
        f = function (x, numbers, n) {
            var res = 0;
            for (var i = 0; i < n+1; i++) res += parseInt(numbers[i]) * Math.pow(x, i);
            return res
        }
    }

    while (a <= b) {
        x.push(a);
        y.push(f(a, numbers, n));
        a += step;
    }
    res = {'name':'Function plot', x:x, y:y };
    return res
}

function buildPlot(divId, options, func, numbers) {
    var plotDiv = document.getElementById(divId);
    if (func) funcPlotStatus = func;
    if (numbers) equationPlotStatus = numbers;
    Plotly.newPlot(
        plotDiv,
        [{
            type:"scatter",
            x: options.x,
            y: options.y
        }],
        {
            title: options.name
        }
    );
}

function checkFieldsEq() {
    var empty = false;
    var $epsilon = $('#epsilonEq');
    if ($epsilon.val() === '') {
        empty = true;
    }

    $('#calcEq').prop('disabled', empty);
}

function checkFieldFunc() {
    var empty = false;
    var $borders = $('.intBorder');
    var $epsilon = $('#epsilonFunc');
    $borders.each(function () {
        if($(this).val() === '' || $epsilon.val() === '')
            empty=true
    });

    $('#calcFunc').prop('disabled', empty);
}

$("input[name='function']").on('click', function () {
    if ($(this).val() === '2') {
        $hybrid = $('option[value="hybrid"]');
        $("option[value='bisection']").prop('disabled', true);
        $hybrid.prop('disabled', false);
        $hybrid.prop('selected', true);
        $("option[value='iteration']").prop('disabled', false);
    }
    if ($(this).val() === '1'){
        $bisection = $("option[value='bisection']");
        $bisection.prop('disabled', false);
        $bisection.prop('selected', true);
        $("option[value='hybrid']").prop('disabled', true);
        $("option[value='iteration']").prop('disabled', true);
    }
});

$(document).ajaxStart(function () {
    $('.loading').show();
});

$(document).ajaxStop(function () {
    $('.loading').hide();
});

var lobachevskyStepTemplate =
    "<tr>\n" +
    "   <td class='col-md-1'>{{p}}</td>\n" +
    "   <td>{{n}}</td>\n" +
    "   {{#numbers}}" +
    "       <td>{{.}}</td>\n" +
    "   {{/numbers}}" +
    "</tr>\n";

var analysisTemplate =
    "<tr>\n" +
    "{{#.}}" +
    "   <td class='text-center' style='width: 25%'>{{.}}</td>\n" +
    "{{/.}}" +
    "</tr>\n";

var standartTemplate =
    "<tr>\n" +
    "{{#.}}" +
    "   <td>{{.}}</td>\n" +
    "{{/.}}" +
    "</tr>\n";

var alertTemplate =
    "<div class=\"alert alert-danger alert-dismissable fade in\">\n" +
    "    <a href=\"#\" class=\"close\" data-dismiss=\"alert\" aria-label=\"close\">&times;</a>\n" +
    "    <strong>Danger!</strong> {{message}}.\n" +
    "</div>";
