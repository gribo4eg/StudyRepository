var studios, films, directors;

var $factsTable = $('#factsTable');
function addFact(fact) {
    $factsTable.slideDown();
    $factsTable.append(Mustache.render(factTemplate, fact));
}

var $modalDiv = $('#modalTarget');
function addModal(template, data) {
    $modalDiv.html(Mustache.render(template, data));
}

$(function () {
    $.ajaxSetup({
        beforeSend: function (xhr, settings) {
            if (!/^(GET|HEAD|OPTIONS|TRACE)$/i.test(settings.type)
                && !this.crossDomain) {
                xhr.setRequestHeader("Content-Type", "application/json")
            }
        }
    });
    $('#loadFilesBtn').prop('disabled', true);
    $('#textSearchField').prop('disabled', true);
    $('#wordTextRadio1').prop('checked', true);

    $.ajax({
        type:'get',
        url:'/api/facts/',
        success: function (data) {
            var facts = data.facts;
            $.each(facts, function (i, fact) {
                addFact(fact);
            });

            $.get('/api/dimensions_names/', function (data) {
                films = data.data.films;
                studios = data.data.studios;
                directors = data.data.directors;
            });
        }
    });
});

$(document).ajaxStart(function() {
    $("#loading").show();
});

$(document).ajaxStop(function () {
    $('#loading').hide();
});

//region POSTING

$('#newInstanceBtn').on('click', function () {

        var data = {
            modal: {
                type: "Create instance",
                header: "Create instance",
                classType: "createBtn"
            },
            fact: {
                films: films,
                directors: directors,
                studios: studios
            }
        };

        addModal(cuModalTemlate, data);
});

$modalDiv.delegate('.createBtn', 'click', function () {

    var data = {
        filmId:$('#filmSelect').val(),
        directorId:$('#directorSelect').val(),
        studioId:$('#studioSelect').val()
    };

    $.ajax({
        type:'post',
        url:'/api/facts/',
        contentType:'application/json',
        data:JSON.stringify(data),
        dataType:'json',
        success:function (result) {
            addFact(result.fact)
        },
        error: function () {
            alert("Error while posting data!")
        }
    });
});

//endregion

//region DELETING

$factsTable.delegate('.deleteBtnModal', 'click', function () {
    var data = {
        id:$(this).attr('data-id'),
        type:"Delete instance",
        classType:"deleteBtn"
    };

    addModal(deletingModalTemplate, data)
});

$modalDiv.delegate('.deleteBtn','click', function () {
    var id = $(this).attr('data-id');
    var $tr = $('#fact'+id);
    $.ajax({
        type:'delete',
        url:'/api/facts/' + id+'/',
        success:function () {
            $tr.fadeOut(500, function () {
                $(this).remove();
            });
        },
        error: function () {
            alert("Error while deleting data!")
        }
    });
});

//endregion

//region EDITING

$factsTable.delegate('.updateBtnModal','click', function () {

    var id = $(this).attr('data-id');
    var $fact =$('#fact'+id).children();
    var dimensions = [
        $fact[1].textContent,
        $fact[2].textContent,
        $fact[3].textContent
    ];

    var filmsN = films.slice(),
        dirN = directors.slice(),
        studN = studios.slice();
    filmsN = changedArray(filmsN, dimensions[0]);
    dirN = changedArray(dirN, dimensions[1]);
    studN = changedArray(studN, dimensions[2]);

    var data = {
        modal: {
            id: $(this).attr('data-id'),
            header:"Update instance",
            type: "Update",
            classType: "updateBtn"
        },
        fact:{
            films:filmsN,
            directors:dirN,
            studios:studN
        }
    };

    addModal(cuModalTemlate, data);

});

function changedArray( array, name) {
    array.unshift(array.splice(array.findIndex(function (obj) {
        return obj.name === name;
    }),1)[0]);
    return array;
}

$modalDiv.delegate('.updateBtn', 'click', function () {

    var selected = [
        film=$('#filmSelect'),
        dir=$('#directorSelect'),
        stud=$('#studioSelect')
    ];
    var data = {
        filmId:selected[0].val(),
        directorId:selected[1].val(),
        studioId:selected[2].val()
    },
        id = $(this).attr('data-id');

    $.ajax({
        type:'put',
        url:'/api/facts/' + id +'/',
        contentType:'application/json',
        data:JSON.stringify(data),
        dataType:'json',
        success:function (result) {
            var fact = $('#fact'+id).children();
            fact[1].textContent =result.fact['film__name'];
            fact[2].textContent = result.fact['director__name'];
            fact[3].textContent = result.fact['studio__name']
        },
        error: function () {
            alert("Error while updating data!")
        }
    });
});

//endregion

//region TRUNCATE

$('#truncateBtnModal').on('click', function () {

    var data = {
        type:"Truncate table",
        classType:"truncateBtn"
    };

    addModal(deletingModalTemplate, data)
});

$modalDiv.delegate('.truncateBtn', 'click', function () {
    $('#loadFilesBtn').prop('disabled', false);
    $.ajax({
        type:'delete',
        url:'/api/facts/',
        success:function () {
            $factsTable.fadeOut(600, function () {
                $(this).children().remove();
            })
        },
        error: function () {
            alert("Error while truncating table!")
        }
    });
});


//endregion

//region SEARCH

//region BOOL

$('#searchOscar').on('click', function () {

    var value = $('#oscar').val();
    $('#searchOscarTable').show();
    $.ajax({
        type: 'get',
        url: '/api/search/directors/?oscar='+value,
        success:function (result) {
            $('#searchOscarTBody').children().remove();
            $.each(result.directors, function (i, obj) {
                $('#searchOscarTBody').append(Mustache.render(oscarTemplate, obj));
            });
        }
    });
});

//endregion

//region NUMBER RANGE

$('#searchRange').on('click', function () {

    var bottom = $('#bottomVal').val(),
        top = $('#topVal').val();
    $('#searchRangeTable').show();
    $.ajax({
        type:'get',
        url:'/api/search/films/?bottom='+bottom+
            '&top='+top,
        success:function (result) {
            $('#searchRangeTBody').children().remove();
            $.each(result.films, function (i, obj) {
                $('#searchRangeTBody').append(Mustache.render(rangeTemplate, obj));
            });
        }
    });
});

//endregion

//endregion

//region TEMPLATES

var factTemplate =
    "<tr id='fact{{id}}'>" +
    "   <td class='col-md-1'>{{id}}</td>" +
    "   <td>{{film__name}}</td>" +
    "   <td>{{director__name}}</td>" +
    "   <td>{{studio__name}}</td>" +
    "   <td>{{date}}</td>" +
    "   <td class='col-md-3 text-center'>" +
    "       <button data-id='{{id}}' class='updateBtnModal btn btn-info btn-sm'" +
    "               data-toggle='modal' data-target='#cuModal'>Edit</button>\n" +
    "       <button data-id='{{id}}' class='deleteBtnModal btn btn-danger btn-sm'" +
    "               data-toggle='modal' data-target='#deletingModal'>Delete</button>" +
    "   </td>" +
    "</tr>";

var oscarTemplate =
    "<tr>" +
    "   <td class='col-md-1'>{{id}}</td>" +
    "   <td>{{name}}</td>" +
    "   <td>{{country}}</td>" +
    "   <td class='col-md-6'>{{bio}}</td>"+
    "</tr>";

var rangeTemplate =
    "<tr>" +
    "   <td class='col-md-1'>{{id}}</td>" +
    "   <td>{{name}}</td>" +
    "   <td>{{duration}}</td>" +
    "   <td>{{budget}}</td>"+
    "</tr>";

var deletingModalTemplate =
    '<div class="modal fade" id="deletingModal" role="dialog">\n' +
    '   <div class="modal-dialog modal-sm">\n' +
    '       <div class="modal-content">\n' +
    '           <div class="modal-header">\n' +
    '               <button type="button" class="close" data-dismiss="modal">&times;</button>\n' +
    '               <h4 class="modal-title">{{type}}!</h4>\n' +
    '           </div>\n' +
    '           <div class="modal-body">\n' +
    '               <p>Are you sure?</p>\n' +
    '           </div>\n' +
    '           <div class="modal-footer">\n' +
    '               <button data-id="{{id}}" class="{{classType}} btn btn-danger"' +
    '                       data-dismiss="modal">Delete</button>'+
    '               <button type="button" class="btn btn-default" data-dismiss="modal">Close</button>\n' +
    '           </div>\n' +
    '       </div>\n' +
    '   </div>\n' +
    '</div>';

var cuModalTemlate =
    '<div class="modal fade" id="cuModal" role="dialog">\n' +
    '   <div class="modal-dialog modal-md">\n' +
    '       <div class="modal-content">\n' +
    '           <div class="modal-header">\n' +
    '               <button type="button" class="close" data-dismiss="modal">&times;</button>\n' +
    '               <h4 class="modal-title">{{modal.header}}</h4>\n' +
    '           </div>\n' +
    '           <div class="modal-body">\n' +
    '               <form class="form-horizontal">\n' +
    '                   <div class="form-group">\n' +
    '                       <label class="control-label col-sm-2" for="filmSelect">Film:</label>\n' +
    '                           <div class="col-sm-10">\n' +
    '                               <select class="form-control" id="filmSelect">\n' +
    '                                   {{#fact.films}}' +
    '                                       <option value="{{ id }}">{{ name }}</option>\n'+
    '                                   {{/fact.films}}' +
    '                               </select>\n' +
    '                           </div>\n' +
    '                   </div>\n' +
    '                   <div class="form-group">\n' +
    '                       <label class="control-label col-sm-2" for="directorSelect">Director:</label>\n' +
    '                           <div class="col-sm-10">\n' +
    '                               <select class="form-control" id="directorSelect">\n' +
    '                                   {{#fact.directors}}' +
    '                                       <option value="{{ id }}">{{ name }}</option>\n'+
    '                                   {{/fact.directors}}' +
    '                               </select>\n' +
    '                           </div>\n' +
    '                   </div>\n' +
    '                   <div class="form-group">\n' +
    '                       <label class="control-label col-sm-2" for="studioSelect">Studio:</label>\n' +
    '                           <div class="col-sm-10">\n' +
    '                               <select class="form-control" id="studioSelect">\n' +
    '                                   {{#fact.studios}}' +
    '                                       <option value="{{ id }}">{{ name }}</option>\n'+
    '                                   {{/fact.studios}}' +
    '                               </select>\n' +
    '                           </div>\n' +
    '                   </div>\n' +
    '                   <div class="form-group">\n' +
    '                       <div class="col-sm-offset-2 col-sm-10">\n' +
    '                           <button data-id="{{modal.id}}" type="button" class="{{modal.classType}} ' +
    '                                   btn btn-primary" data-dismiss="modal">{{modal.type}}</button>' +
    '                       </div>\n' +
    '                   </div>\n' +
    '              </form>' +
    '           </div>\n' +
    '           <div class="modal-footer">\n' +
    '               <button type="button" class="btn btn-default" data-dismiss="modal">Close</button>\n' +
    '           </div>\n' +
    '       </div>\n' +
    '   </div>\n' +
    '</div>';

//endregion