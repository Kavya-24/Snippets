const menu = document.querySelector('#menu');
const menuLinks = document.querySelector('.navbar-menu');
const navLogo = document.querySelector('#icon')
// display menu

const mobileMenu = () => {
      menu.classList.toggle('is-active');
      menuLinks.classList.toggle('active');


};
menu.addEventListener('click' , mobileMenu);

// show active menu when scrolling


const highLightMenu = () => {
     const elen = document.querySelector('.highlight')
     const home = document.querySelector('#home-page')
     const about = document.querySelector('#about-page')
     const service = document.querySelector('#service-page')
     let  scrollPos = window.scrollY 
//      console.log(scrollPos);

// adds 'highlight' class to my menu items

     if(window.innerWidth > 960 && scrollPos < 600) {
        home.classList.add('highlight')
        about.classList.remove('highlight')
        return
 


     } else if(window.innerWidth > 960 && scrollPos <1400 ){

       about.classList.add('hightlight')
       home.classList.remove('highlight')
       service.classList.remove('highlight')
       return

     }

     else if(window.innerWidth > 960 && scrollPos < 2345){
      service.classList.add('highlight')
      about.classList.remove('hightlight')
     
    
      return

    }


    if((elen && window.innerWidth < 960 && scrollPos < 600 ) || elen) {
           elen.classList.remove('highlight')




    } 




}

window.addEventListener('scroll' , highLightMenu)

window.addEventListener('click' , highLightMenu)

// close mobile menu when clicking on a menu item


const hideMobileMenu = () => {

  const menuBars = document.querySelector('.is-active')
  if(window.innerwidth <= 768 && menuBars) {
 
        menu.classList.toggle('.is-active')
        menuLinks.classList.remove('active')



  }


}

menuLinks.addEventListener('click' , hideMobileMenu);
navLogo.addEventListener('click' , hideMobileMenu);

