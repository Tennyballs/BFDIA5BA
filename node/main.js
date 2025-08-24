var fs = require('fs');
var obj;
fs.readFile('texture.json', 'utf8', function (err, data) {
    if (err) throw err;
    obj = JSON.parse(data);
    let line = ``;
    obj.frames.forEach((frame) => {
        let f = frame.frame

        line += `${f.x},${f.y},${f.w},${f.h};`;
    })
    console.log(line);
});