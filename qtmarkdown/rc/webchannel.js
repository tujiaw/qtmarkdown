(function(global) {
  window.webchannel = null;
  new QWebChannel(qt.webChannelTransport, function(channel) {
    window.webchannel = channel.objects.ssevent;
    var req = {
      cmd: "getName",
      value: '100',
    }
    wenchannel.request("getName", JSON.stringify(req));
  });

})(this);
