const btn = document.querySelector('button');
const global = document.querySelector('html');

btn.addEventListener('click', changeColor);

function changeColor()
{
    let newColor = 'rgba(' + Math.floor(Math.random()*255+1) + ',' + Math.floor(Math.random()*255+1) + ',' + Math.floor(Math.random()*255+1) + ',' + Math.floor(Math.random()+1) + ')';
    global.style.backgroundColor = newColor;
}