
import './App.css';
import React, {useState, useEffect} from 'react';
// import logo from './kisspng-leaf-logo-brand-plant-stem-folha-5acb0798d686f9.0092563815232551928787.jpg'
import Axios from "axios";
// console.log(logo);


function App() {
  
  const [humidite, setHumidite] = useState("")
  const [temperature, setTemperature] = useState("")
  const [luminosite, setLuminosite] = useState("")
  const [plantLogList, setLogPlant] = useState([])

  useEffect(() => {
    Axios.get('http://87.89.194.28:4000/api/get').then((response) => {
      setLogPlant(response.data)
    });
  }, []);

  const submitPlantValue = () => {
    Axios.post('http://87.89.194.28:2000/api/insert',{
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
  {plantLogList.map((val) => {
    return <h1> Temperature : {val.temperature} | luminosite : {val.luminosite} | humidite : {val.luminosite}</h1>
  })}
  </div>
    </div>
  );
}

export default App;
