 window.onload = function () {
        console.log("on load....");
        let user_id = "100000";
        let video_id = "100000";
        var queryJson = [];
        var row = {};
        row.user_id = user_id;
        row.video_id = video_id;
        queryJson.push(row);

        $.ajax({
            url: "/Video/Index",
            async: false,
            type: 'post',
            contentType: "application/json",
            data: JSON.stringify(queryJson[0]),
            dataType: "json",
            traditional: true,
            success: function (data) {
                var data = eval("(" + data + ")");
                console.log(data);

                //TODO
                var comment_list = document.getElementById("comment_list");
                comment_data.forEach(function (item, index) {
                    var newComment = document.createElement('div');
                    comment_list.appendChild(newComment);
                    newComment.innerHTML = ['<div class="list-item">\n' +
                        '                        <div class="user-face">\n' +
                        '                            <img src="' + item.commenter_avatar + '" class="user-head">\n' +
                        '                        </div>\n' +
                        '                        <div class="con">\n' +
                        '                            <div class="user">\n' +
                        '                                <span style="border-color: #5896de; color: #5896de;">\n' +
                        '                                    "' + item.commenter_nickname + '"\n' +
                        '                                </span>\n' +
                        '                            </div>\n' +
                        '                            <p class="text" style="text-align: left;">\n' + item.comment_content + '\n' +
                        '                            </p>\n' +
                        '                            <div class="info">' + item.comment_time + '</div>\n' +
                        '                        </div>\n' +
                        '\n' +
                        '                    </div>'];
                })

          
                
            },
            error: function (message) {
                alert("请求查询数据失败！");
            }
        });
    }
