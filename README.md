Another Arduino-powered Billy "Bertha" bass project. This one sings "Du Hast" and "I don't wanna be me". 

Due to using an 8-bit controller, none of the native SD and audio libraries from aurdino would work. I found a work around via outputting analog audio on a single pin with: <a Href = "https://github.com/TMRh20/TMRpcm">TMRpcm</a>. **Requires a FAT16 SD card 4 gigs or smaller**

The audio is not amazing, especially out of the stock Bass speaker, and it has a little 60 cycle hum I wasn't able to ground away. 

That said, I would like to do an improved version of this in the future with a 32-bit controller. 

gear used is listed in the INO. 
