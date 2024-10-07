
var buttonColours = ["red", "blue", "green", "yellow"];

var gamePattern = [];
var userClickedPattern = [];

var started = false;
var level = 0;

$(document).keypress(function(e) {
  if(e.key === 'Enter'){
    if (!started) {
      $("#level-title").text("Level " + level);
      nextSequence();
      started = true;
    }
  }
});

const keyToColor = (key) => {
  switch(key) {
    case 'w':
      return 'green';
    case 'a':
      return 'red';
    case 's':
      return 'yellow';
    case 'd':
      return 'blue';
    default:
      return '-1';
  }
}

$(document).keydown(function (e){
  if(!started) return;
  console.log(e.key)
  const color = keyToColor(e.key);
  for(let i = 0; i < buttonColours.length; i++) {
    if(color === buttonColours[i]) {
      userClickedPattern.push(color);
      playSound(color);
      animatePress(color);
      checkAnswer(userClickedPattern.length-1);
    }
  }
})

$(".btn").click(function() {

  var userChosenColour = $(this).attr("id");
  userClickedPattern.push(userChosenColour);

  playSound(userChosenColour);
  animatePress(userChosenColour);

  checkAnswer(userClickedPattern.length-1);
});

function checkAnswer(currentLevel) {

    if (gamePattern[currentLevel] === userClickedPattern[currentLevel]) {
      if (userClickedPattern.length === gamePattern.length){
        setTimeout(function () {
          nextSequence();
        }, 1000);
      }
    } else {
      playSound("wrong");
      $("body").addClass("game-over");
      $("#level-title").text("Game Over, Press ENTER to Restart");

      setTimeout(function () {
        $("body").removeClass("game-over");
      }, 200);

      startOver();
    }
}


function nextSequence() {
  userClickedPattern = [];
  level++;
  $("#level-title").text("Level " + level);
  var randomNumber = Math.floor(Math.random() * 4);
  var randomChosenColour = buttonColours[randomNumber];
  gamePattern.push(randomChosenColour);

  $("#" + randomChosenColour).fadeIn(100).fadeOut(100).fadeIn(100);
  playSound(randomChosenColour);
}

function animatePress(currentColor) {
  $("#" + currentColor).addClass("pressed");
  setTimeout(function () {
    $("#" + currentColor).removeClass("pressed");
  }, 100);
}

function playSound(name) {
  var audio = new Audio("./sound/" + name + ".mp3");
  audio.play();
}

function startOver() {
  level = 0;
  gamePattern = [];
  started = false;
}