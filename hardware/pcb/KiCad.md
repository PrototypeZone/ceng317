# KiCad   
1. We will be designing a Raspberry Pi Interface board using KiCad.
2. Chapter 18 of the below textbook on pages 259-284, pages 268-293 of the pdf, has Project 2: Design a small Raspberry Pi HAT.
   Dalmaris, P. (2018). KiCad Like a Pro 2nd edition. United Kingdom: Elektor International Media B.V. Tech Explorations: EBOOK SOLO 978-1-64440-886-5. Note that newer versions of the textbook do not include this project.   
3. Launch KiCad:   
![](media/1.png)
4. Start with default settings:   
![](media/2.png)
5. I have followed [Using a template](https://techexplorations.com/guides/kicad/3e/create-a-new-kicad-project-from-a-template/)https://techexplorations.com/guides/kicad/3e/create-a-new-kicad-project-from-a-template/ and [Vlad's guide to PCB facilities in J233](PCBPrototypes.md) to a certain extent in order to create the:
-   [Project File](/hardware/pcb/StudentName2023-09-24.kicad_pro)
-   [Schematic File](/hardware/pcb/StudentName2023-09-24.kicad_sch)
-   [PCB File](/hardware/pcb/StudentName2023-09-24.kicad_pcb)   
6. Download /hardware/pcb/StudentName2023-09-24.kicad_pro, pcb, and sch.   
- Use KiCad to change the board to have your name and the current date.
- Connect the BJT as a switch circuit (Section 4.5 Page 192 in your Electronic Devices by Floyd) traces on the PCB.   
- Save "project as" what you changed the name and date to.   
- Use File->fabrication outputs->Gerbers (.gbr)...   
- also "Generate Drill Files"->PTH and NPTH in single file   
- Save project   
- Upload to /hardware/pcb/ what you changed the name and date to as a zip (StudentName2023-09-24.zip) it should contain the defaults of:   
   1. F.Cu   
   2. B.Cu   
   3. F.Silkscreen   
   4. B.Silkscreen   
   5. F.Mask   
   6. B.Mask   
   7. Edge.Cuts   
   8. The drill file   
   9. Your _pro file   
   10. Your _sch file   
   11. Your _pcb file   
