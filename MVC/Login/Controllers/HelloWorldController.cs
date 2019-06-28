using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace myApp.Controllers
{
    public class HelloWorldController : Controller
    {
        // GET: HelloWorld
        public ActionResult Index()
        {
            return View();
        }

        public ActionResult Login()
        {
            ViewBag.LoginState = "登陆前...";
            return View();
        }


        [HttpPost]
        public ActionResult Login(FormCollection formcollection)
        {
            string email = formcollection["inputEmail3"];
            string password = formcollection["inputPassword3"];

            using (System.IO.StreamWriter sw = System.IO.File.AppendText("F:\\coding in VS\\myApp\\log.txt"))
            {
                sw.WriteLine("用户输入的email为: "+email);
                sw.WriteLine("用户输入的password为: "+password);
            }


            ViewBag.LoginState = email + "登陆后...";
            return View();
        }
    }
}