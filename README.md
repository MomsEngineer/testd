# testd
A unix test daemon that sends messages to the syslog.

# Install
1. Download the daemon. Get the daemon you can two ways:
      * First way:
          - Click the button "Clone or download".
          - Click "Download zip".
      * Second way:
          - In the terminal, run the command:
          ````
          git clone https://github.com/MomsEngineer/testd.git
          ````
 2. Buld and install the daemon:
     <details>
       <summary>If you have used first way:</summary>
  
       - Install `unzip` if you don't have this util
         ````
         sudo apt install unzip
         ````
       - Unzip the downloaded zip file
         ````
         unzip testd-master.zip
         ````
     </details>
 
     - Go to the directory with the daemon code
       ````
       cd testd-master
       ````
     - Run command to build code
       ````
       make
       ````
     - Run command to install the daemon
       ````
       make install
       ````
     - Run command to clear the directory of unnecessary files
       ````
       make clean
       ````
    Installation done. The daemon is installed and ready to use. The daemon executable is “testd” and is located in /usr/local/bin.
