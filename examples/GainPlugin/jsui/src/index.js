import connectToDevTools from 'juce-blueprint-devtools';
import React from 'react';
import App from './App';
import Blueprint from 'juce-blueprint';
connectToDevTools();
Blueprint.render(<App />, Blueprint.getRootContainer());