const fs = require('fs');

let content = fs.readFileSync('input.txt', 'utf-8');

function solve(){
    
    function fill(w,x,y,st){
        if(!arr[x])
            arr[x] = {};
        if(!arr[x][y])
            arr[x][y] = {l:0,c:0,s:0};
        if(w != arr[x][y].l){
            arr[x][y].l = w;
            arr[x][y].c ++;
            if(arr[x][y].c > 1){
                resA = Math.min(resA, Math.abs(x-cx)+Math.abs(y-cy));
                resB = Math.min(resB, arr[x][y].s+st);
            }
            arr[x][y].s = st;
        }
    }
    
    let inp = content.split('\n').map(a=>a.split(','));
    let arr = {};
    
    let cx = 10000, cy = 10000;
    let resA = Infinity, resB = Infinity;
    
    let ind = 0;
    for(let line of inp){
        ind++;
        let posX = cx;
        let posY = cy;
        let step = 0;
        for(let p of line){
            let what = p[0];
            let num = parseInt(p.substr(1));
            
            switch(what){
                case 'U':
                    while(num--) fill(ind,posX,++posY,++step); break;
                case 'R':
                    while(num--) fill(ind,++posX,posY,++step); break;
                case 'D':
                    while(num--) fill(ind,posX,--posY,++step); break;
                case 'L':
                    while(num--) fill(ind,--posX,posY,++step); break;
            }
        }
    }
    
    console.log(resA, resB);
}

solve();