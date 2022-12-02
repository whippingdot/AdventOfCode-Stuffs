const day = document.querySelector('input');

day.addEventListener('keydown', async e => {
    if(e.key != 'Enter') return;
    const d = Number(day.value);
    const loc = '/solutions/day' + d;
    const txt = await (await fetch(loc + '/input.txt')).text();
    const func = (await import(loc + '/solution.js')).default;
    alert(func(txt));
})