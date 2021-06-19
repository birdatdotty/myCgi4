import Service 
import RouterAPI
import RouterHTML
import SimpleHTTPServer

Service {
  id: main
  root: "/tmp/sss/"

  RouterAPI {
    root: main.root
    url: "/api"
    loginFile: "/var/users.json"
    noteFile: "/var/notes.json"
  }
  RouterHTML {
    root: main.root + "/html";
    url: "/";
    defaultPage: "index.html"
  }
  
  SimpleHTTPServer {
    port: 9999
  }
}

Service RouterAPI RouterHTML SimpleHTTPServer
