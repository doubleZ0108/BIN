using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using System.IO;
using System.Web.Script.Serialization;
using Newtonsoft.Json.Linq;

namespace HeadFoot.Controllers
{
    public class MainController : Controller
    {
        // GET: Main
        public ActionResult Index()
        {
            return View();
        }

        public ActionResult Button()
        {
            return View();
        }
        [HttpPost]
        public ActionResult Button(string id, string name)
        {
            using (System.IO.StreamWriter sw = System.IO.File.AppendText("E:\\document\\log.txt"))
            {
                sw.WriteLine(id);
            }

            var state = new
            {
                id = "999",
                name = "zyT"
            };

            return Json(JsonConvert.SerializeObject(state, Formatting.Indented));
        }


    }
}
