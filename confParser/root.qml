import Service 
import RouterAPI
import RouterHTML
import SimpleHTTPServer
import TestLib

Service {
  id: main
  name: "SERVER"
  root: "/tmp/sss/"

  RouterAPI {
    root: main.root
    id: routerAPI
    url: "/api"
    loginFile: "/var/users.json"
    noteFile: "/var/notes.json"
  }
  RouterHTML {
    id: routerHTML
    root: main.root + "/html";
    url: "/";
    defaultPage: "index.html"
  }
  
  SimpleHTTPServer {
    id: simpleHTTPServer
    port: 9933
  }
  SimpleHTTPServer {
    id: simpleHTTPServer2
    port: 9934
  }

  TestLib {
      id:ss
  }
}

Service RouterAPI RouterHTML SimpleHTTPServer
