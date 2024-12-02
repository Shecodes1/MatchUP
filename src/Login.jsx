import React, { useState, useEffect } from "react";

export default function Login() {
  return TryLogin();
}


function TryLogin(){
  const API_URL = "http://4.237.58.241:3000/user/login";
  const [usrData, setusrData] = useState([]);
  const [email, setEmail] = useState("");
  const [password, setPassword] = useState("");
  const [clicked, setClicked] = useState(false);

  const handleEmailChange = (event) => {
    setEmail(event.target.value);
  };

  const handlePasswordChange = (event) => {
    setPassword(event.target.value);
  };

  const handleLoginClick = () => {
    setClicked(true);
  };

  
  useEffect(() => {
    if (!clicked) return;
      const fetchData = async () => {
        try {
          const res = await fetch(API_URL, {
            method: 'POST',
            headers: {
              'Content-Type': 'application/json'
            },
            body: JSON.stringify({ email, password })
          });
          const data = await res.json();

          const UserData = {
            token: data.token,
            token_type: data.token_type,
            expires_in: data.expires_in,
            error: data.error,
            message: data.message
          };
  
          setusrData(UserData);
        } catch (error) {
          // Handle errors here
          console.error('Error fetching data:', error);
        }
      };
      
      if (usrData.error == true){
        window.alert('An error occured')
      }
      fetchData();
    }, [clicked, email, password]);

    localStorage.setItem("token", usrData.token);
    localStorage.setItem("token_type", usrData.token_type);
    localStorage.setItem("expires_in", usrData.expires_in);
    
    return (
      <div>
        <input
          type="text"
          placeholder="Enter your email"
          value={email}
          onChange={handleEmailChange}
          style={{ width: '300px', height: '80px', fontSize: '25px', marginBottom: '10px' }}
        />
        <input
          type="password"
          placeholder="Enter your password"
          value={password}
          onChange={handlePasswordChange}
          style={{ width: '300px', height: '80px', fontSize: '25px', marginBottom: '10px' }}
        />
        <button onClick={handleLoginClick} style={{ width: '320px', height: '80px', fontSize: '25px' }}>
          Login</button>
        {usrData && (
          <div style={{backgroundColor: "white", padding: "20px", fontSize: "1.5em" }}>
            <h3>Message:</h3>
            {usrData.error ? (
            <p style={{ color: 'red' }}>Error: {usrData.message}</p>
          ) : (
            <div>
              <p>Please enter your email and password to login in!</p>
            </div>
          )}
          {usrData.token ? (
            <p>You are currently logged in.</p>) : (
            <div>
              <p></p>
            </div>
          )}
          </div>
        )}
      </div>
    );
  }
