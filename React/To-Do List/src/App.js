import React, { useState, useRef } from 'react';
import './App.css';
import BackgroundChanger from "./BackgroundChanger.js"
import ColorChanger from "./ColorChanger.js"
import MusicPlayer from "./MusicPlayer.js"
import ToDoList from "./ToDoList.js"


export default function App() {
  return (
    <ToDoList />,
    <BackgroundChanger />,
    <ColorChanger />,
    <MusicPlayer />,
  );
}
