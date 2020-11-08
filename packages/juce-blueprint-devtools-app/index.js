const {app, BrowserWindow} = require('electron');

let mainWindow = null;
app.on('window-all-closed', function() {
  app.quit();
});

app.on("ready", function() {
  mainWindow = new BrowserWindow({
    width: 800,
    height: 600,
    frame: true,
    webPreferences: {
      nodeIntegration: true
    }
  });

  mainWindow.loadURL('file://' + __dirname + '/app.html');
  mainWindow.on('closed', function() {
    mainWindow = null;
  });
});

