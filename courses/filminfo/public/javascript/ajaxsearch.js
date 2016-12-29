
$(function () {
    $('#searchfield').on('submit', function (result) {
        result.preventDefault();

        var filmtitle = $('#filmtitle');
        filmtitle = filmtitle.val();
        
        $.ajax({
            url: '/api/search/films/'+filmtitle,
            method: 'get',
            contentType: 'application/json',
            success: function (answer) {
                var mustach = document.getElementById('mustache-script').innerHTML;
                var html = null;

                var film = answer;

                if(film){
                    html = Mustache.render(mustach, {
                        films:film,
                        empty:false
                    });
                } else {
                    html = Mustache.render(mustach, {
                        empty:true
                    });
                }

                document.getElementById('results').innerHTML = html;
            }
        })
    })
});