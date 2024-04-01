// let cursor = document.querySelector(':rebak-spalinowy');

for(let i = 1; i <=7; i++){
  const image = document.querySelector('.z'+i);
  const description = document.querySelector('.t'+i);
  image.addEventListener('click', () => {
    description.classList.add('zoomed');
    image.classList.remove('zoomable');
    description.addEventListener('click', () => {
      description.classList.remove('zoomed');
      image.classList.add('zoomable');
    });
  });
}
