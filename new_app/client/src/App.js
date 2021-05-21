
import './App.css';
import React, {useState} from 'react';
// import logo from './kisspng-leaf-logo-brand-plant-stem-folha-5acb0798d686f9.0092563815232551928787.jpg'
import Axios from "axios";
// console.log(logo);


function App() {
  
  const [humidite, setHumidite] = useState('')
  const [temperature, setTemperature] = useState('')
  const [luminosite, setLuminosite] = useState('')

  const submitPlantValue = () => {
    Axios.post('http://87.89.194.28:4000',{
    temperature: temperature,
    humidite: humidite,
    luminosite: luminosite,
  }).then(() => {
    alert("succesful insert");
  });
  };

  return (
    <div className="App">
    <h1>Welcome to the Kube 2</h1>
	<div className="form">
    <label>temperature:</label>
  <input type="number" name="temperature" onChange={(e)=>
      setTemperature(e.target.value)} />
  <label>humidite:</label>
  <input type="number" name="humidite" onChange={(e)=>
      setHumidite(e.target.value)} />
  <label>luminosite:</label>
  <input type="number" name="luminosite" onChange={(e)=>
      setLuminosite(e.target.value)}/>
  <button onClick={submitPlantValue}>Submit</button>
  </div>
    </div>
  );
}

export default App;
