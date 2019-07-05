using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using myApp.Models;

namespace myApp.Controllers
{
    public class HelloWorldController : Controller
    {
        // GET: HelloWorld
        public ActionResult Index()
        {
            return View();
        }

        public ActionResult Home()
        {
            ViewData["para1"] = "This is a title";
            ViewData["para2"] = "This is paragraphy 1";

            return View();
        }

        [HttpPost]
        public ActionResult Home(FormCollection formcollection)
        {
            if(formcollection["action"]=="btn1")
            {
                ViewData["para1"] = "click.........";
                ViewData["para2"] = "按钮11111111111";
            }
            else if (formcollection["action"]=="btn2")
            {
                ViewData["para1"] = "click.........";
                ViewData["para2"] = "按钮22222222222";
            }

            return View();
        }
        

    }
}
