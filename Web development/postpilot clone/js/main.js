const toggle_button_open = document.getElementById("toggle-button-open");
const toggle_button_close = document.getElementById("toggle-button-close");
const navbar_wrapper = document.getElementById("navbar-wrapper");
const navbar_links = document.getElementById("navbar-links");


toggle_button_open.addEventListener('click', () => {
    navbar_wrapper.style.pointerEvents = "all";
    navbar_links.style.transform = "translateX(0%)";
    navbar_wrapper.style.opacity = "1";
});

toggle_button_close.addEventListener('click', () => {
    navbar_wrapper.style.pointerEvents = "none";
    navbar_links.style.transform = "translateX(100%)";
    navbar_wrapper.style.opacity = "0";
});

navbar_wrapper.addEventListener('click', () => {
    navbar_wrapper.style.pointerEvents = "none";
    navbar_links.style.transform = "translateX(100%)";
    navbar_wrapper.style.opacity = "0";
});