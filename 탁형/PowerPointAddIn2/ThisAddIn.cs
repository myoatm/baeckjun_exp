using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Xml.Linq;
using PowerPoint = Microsoft.Office.Interop.PowerPoint;
using Office = Microsoft.Office.Core;
using System.IO;
using System.Windows.Forms;

using PPT = Microsoft.Office.Interop.PowerPoint;

namespace PowerPointAddIn2
{
    public partial class ThisAddIn
    {
        private void ThisAddIn_Startup(object sender, System.EventArgs e)
        {
            // 매 슬라이드마다 넣는 것. 라이센스용도로 좋을듯
            //this.Application.PresentationNewSlide += new PowerPoint.EApplication_PresentationNewSlideEventHandler(newText);
            this.Application.AfterNewPresentation += new PowerPoint.EApplication_AfterNewPresentationEventHandler(delDefaultSlide);
            this.Application.AfterNewPresentation += new PowerPoint.EApplication_AfterNewPresentationEventHandler(newSlideManager);

        }

        private void ThisAddIn_Shutdown(object sender, System.EventArgs e)
        {
        }
        void newtxt(PPT.Slide sld) {
            PowerPoint.Shape textBox = sld.Shapes.AddTextbox(
                Office.MsoTextOrientation.msoTextOrientationHorizontal, 100, 100, 500, 50);
            textBox.TextFrame.TextRange.InsertAfter("주의은혜라");
        }
        void newSlideManager(PPT.Presentation pres) {
            StreamReader sr = new StreamReader("D:\\lyrics.txt");
            string lyrics = sr.ReadToEnd();
            
            string[] ly = lyrics.Split('\n');

            string tmp= "";
            for(int i=0; i<ly.Length; i++) {
                tmp += ly[i];
                if (ly[i].Trim() == "") {
                    
                    newSlideWithText(pres, tmp, 100, 100);
                    tmp = "";
                }
            }
            if(tmp != "") {
                newSlideWithText(pres, tmp, 100, 100);
            }




        }

        void delDefaultSlide(PPT.Presentation pres) {
            pres.Slides[1].Delete();
        }

        void newSlideWithText(PPT.Presentation pres, String text, int _x, int _y) {

            /*
            PPT.CustomLayout customLayout = null;
            PPT.Slide activeSlide = null;

            customLayout = Globals.ThisAddIn.Application.ActivePresentation.SlideMaster.CustomLayouts[3]; // 빈화면 고르는듯
            activeSlide = Globals.ThisAddIn.Application.ActivePresentation.Slides.AddSlide(0, customLayout);
            */

            int insertNextSlideIdx = pres.Slides.Count + 1;
            PowerPoint.Slide sld = pres.Slides.AddSlide(insertNextSlideIdx, pres.SlideMaster.CustomLayouts[3]);
            PowerPoint.Shape textBox = sld.Shapes.AddTextbox(
            Office.MsoTextOrientation.msoTextOrientationHorizontal, _x, _y, 500, 50);
            textBox.TextFrame.TextRange.InsertAfter(text);


        }

        #region VSTO에서 생성한 코드

        /// <summary>
        /// 디자이너 지원에 필요한 메서드입니다. 
        /// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
        /// </summary>
        private void InternalStartup()
        {
            this.Startup += new System.EventHandler(ThisAddIn_Startup);
            this.Shutdown += new System.EventHandler(ThisAddIn_Shutdown);
        }
        
        #endregion
    }
}
