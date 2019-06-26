using Microsoft.AspNetCore.Mvc;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using myapp.Models.TestModels;

namespace myapp.Controllers
{
    public class MyController : Controller
    {
        public string HelloWorld()
        {
            return "Hello world";
        }

        public IActionResult CurrentTime()
        {
            return Json(new { time = DateTime.Now.ToString() });
        }

        public IActionResult Test(int id)
        {
            id *= id;

            var model = new TestModel();
            model.MyNumber = id;

            return View(model);
        }
    }
}
