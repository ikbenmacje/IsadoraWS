# ReadMe

*This example is to be used together with: IsadoraNetwerk.izz*

In this folder you will find a processing sketch (https://processing.org/) that can recieve OSC data as an example that you can use OSC to send date bertween different programs.

If you use the Isadora example and the Processing example on th esame computer make sure that:
- Isadora sends to port 1235
- Processing Sketch listens to port 1235

This is because it you do not listen to the same port in Processing as the port from which you send in Isadora you will not recieve the messages. Isadora by default listens to port 1234 so we cannot use that port because a OSC listening port can be openend only by one program at a time.
