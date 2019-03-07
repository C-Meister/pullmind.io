const mode = process.argv[2];

if (mode === "--web") {
  const ws = require("ws");

  new ws.Server({
    port: 3333
  }).on("connection", socket => {
    socket.on("message", data => {});
  });
  console.log("WebSocket Server Open");
} else {
  require("net")
    .createServer(socket => {
      socket.on("data", data => {
        const msg = data.toString();
        if (msg === "ping") {
          return socket.write("pong");
        }
        
      });
      socket.on("close", err => {
        if (err) console.error(err);
      });
      socket.on("error", err => {
        console.error(err);
      });
    })
    .listen(3333);
  console.log("TCP Server Open");
}
