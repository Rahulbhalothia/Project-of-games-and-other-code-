const API_KEY="2c951b0f4e4c4f78bf173543261603"


function searchWeather(){

let city=document.getElementById("cityInput").value

fetch(`https://api.weatherapi.com/v1/current.json?key=${API_KEY}&q=${city}`)

.then(res=>res.json())

.then(data=>updateUI(data))

}



navigator.geolocation.getCurrentPosition(position=>{

let lat=position.coords.latitude
let lon=position.coords.longitude

fetch(`https://api.weatherapi.com/v1/current.json?key=${API_KEY}&q=${lat},${lon}`)

.then(res=>res.json())

.then(data=>updateUI(data))

})



function updateUI(data){

document.getElementById("temp").innerHTML=data.current.temp_c+"°C"

document.getElementById("condition").innerHTML=data.current.condition.text

document.getElementById("humidity").innerHTML=data.current.humidity+"%"

document.getElementById("wind").innerHTML=data.current.wind_kph+" km/h"

document.getElementById("pressure").innerHTML=data.current.pressure_mb+" mb"

document.getElementById("cityName").innerHTML=data.location.name

document.getElementById("icon").src="https:"+data.current.condition.icon


if(data.current.condition.text.includes("rain")){

createRain()

}

}



function createRain(){

let rain=document.getElementById("rain")

rain.innerHTML=""

for(let i=0;i<80;i++){

let drop=document.createElement("span")

drop.style.left=Math.random()*100+"vw"

drop.style.animationDelay=Math.random()+"s"

rain.appendChild(drop)

}

}



let hour=new Date().getHours()

if(hour>6 && hour<18){

document.body.style.background="linear-gradient(#4facfe,#00f2fe)"

}else{

document.body.style.background="linear-gradient(#141E30,#243B55)"

}