﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace injectedmethods._System.Web.Hosting {
        class LargeGenerics<a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32, a33, a34, a35, a36, a37, a38, a39, a40, a41, a42, a43, a44, a45, a46, a47, a48, a49, a50, a51, a52, a53, a54, a55, a56, a57, a58, a59, a60, a61, a62, a63, a64, a65, a66, a67, a68, a69, a70, a71, a72, a73, a74, a75, a76, a77, a78, a79, a80, a81, a82, a83, a84, a85, a86, a87, a88, a89, a90, a91, a92, a93, a94, a95, a96, a97, a98, a99, a100, a101, a102, a103, a104, a105, a106, a107, a108, a109, a110, a111, a112, a113, a114, a115, a116, a117, a118, a119, a120, a121, a122, a123, a124, a125, a126, a127, a128, a129, a130, a131, a132, a133, a134, a135, a136, a137, a138, a139, a140, a141, a142, a143, a144, a145, a146, a147, a148, a149, a150, a151, a152, a153, a154, a155, a156, a157, a158, a159, a160, a161, a162, a163, a164, a165, a166, a167, a168, a169, a170, a171, a172, a173, a174, a175, a176, a177, a178, a179, a180, a181, a182, a183, a184, a185, a186, a187, a188, a189, a190, a191, a192, a193, a194, a195, a196, a197, a198, a199, a200, a201, a202, a203, a204, a205, a206, a207, a208, a209, a210, a211, a212, a213, a214, a215, a216, a217, a218, a219, a220, a221, a222, a223, a224, a225, a226, a227, a228, a229, a230, a231, a232, a233, a234, a235, a236, a237, a238, a239, a240, a241, a242, a243, a244, a245, a246, a247, a248, a249, a250, a251, a252, a253, a254, a255, a256, a257, a258, a259, a260, a261, a262, a263, a264, a265, a266, a267, a268, a269, a270, a271, a272, a273, a274, a275, a276, a277, a278, a279, a280, a281, a282, a283, a284, a285, a286, a287, a288, a289, a290, a291, a292, a293, a294, a295, a296, a297, a298, a299, a300, a301, a302, a303, a304, a305, a306, a307, a308, a309, a310, a311, a312, a313, a314, a315, a316, a317, a318, a319, a320, a321, a322, a323, a324, a325, a326, a327, a328, a329, a330, a331, a332, a333, a334, a335, a336, a337, a338, a339, a340, a341, a342, a343, a344, a345, a346, a347, a348, a349, a350, a351, a352, a353, a354, a355, a356, a357, a358, a359, a360, a361, a362, a363, a364, a365, a366, a367, a368, a369, a370, a371, a372, a373, a374, a375, a376, a377, a378, a379, a380, a381, a382, a383, a384, a385, a386, a387, a388, a389, a390, a391, a392, a393, a394, a395, a396, a397, a398, a399, a400, a401, a402, a403, a404, a405, a406, a407, a408, a409, a410, a411, a412, a413, a414, a415, a416, a417, a418, a419, a420, a421, a422, a423, a424, a425, a426, a427, a428, a429, a430, a431, a432, a433, a434, a435, a436, a437, a438, a439, a440, a441, a442, a443, a444, a445, a446, a447, a448, a449, a450, a451, a452, a453, a454, a455, a456, a457, a458, a459, a460, a461, a462, a463, a464, a465, a466, a467, a468, a469, a470, a471, a472, a473, a474, a475, a476, a477, a478, a479, a480, a481, a482, a483, a484, a485, a486, a487, a488, a489, a490, a491, a492, a493, a494, a495, a496, a497, a498, a499, a500, a501, a502, a503, a504, a505, a506, a507, a508, a509, a510, a511, a512, a513> { }


        [CustomAttribute.AssemblyTypeInformation ("System.Web.dll", "System.Web.Hosting.PipelineRuntime")]
        class PipelineRuntime {
                [System.Runtime.InteropServices.DllImport ("clrprofiler.dll")]
                extern static public void NtvEnterHttp (System.UInt64 mdToken, System.UInt64 methodDef,
                        string method, int responseCode, int subCode, string request, string queryString,
                        string body, string [] headers, string [] cookes, string [] session);

                [CustomAttribute.LocalVariableFixup (0, 0, "System.Web.Hosting.IIS7WorkerRequest"), CustomAttribute.LocalVariableFixup (1, 1, "System.Web.HttpContext")]
                public void ProcessRequest_Inject () {
                        System.Web.HttpWorkerRequest workerRequest = null;      
                        System.Web.HttpContext context = null;
                        ProcessRequest_Enter (workerRequest, context);
                }
                public static void ProcessRequest_Info (System.Web.HttpWorkerRequest workerRequest, System.Web.HttpContext context) {
                        if ( context != null ) {
                                List<string> headers = new List<string> ();
                                List<string> cookies = new List<string> ();
                                List<string> session = new List<string> ();
                                List<int> session2 = new List<int> ();
                                string httpMethod = string.Empty;
                                string httpUrl = string.Empty;
                                string httpQueryString = string.Empty;
                                string body = string.Empty;
                                byte [] buffer = null;
                                int statusCode = 0;
                                int substatusCode = 0;
                                if ( context.Response != null ) {
                                        statusCode = context.Response.StatusCode;
                                        substatusCode = context.Response.SubStatusCode;
                                }
                                if ( context.Request != null ) {
                                        if ( context.Request.Headers != null ) {
                                                foreach ( var item in context.Request.Headers ) {
                                                        headers.Add (item.ToString ());
                                                }
                                        }
                                        if ( context.Request.Cookies != null ) {
                                                foreach ( var item in context.Request.Cookies ) {
                                                        cookies.Add (item.ToString ());
                                                }
                                        }
                                        if ( context.Request.InputStream != null ) {
                                                if ( context.Request.InputStream.Length > 0 ) {
                                                        buffer = new byte [context.Request.InputStream.Length];
                                                        context.Request.InputStream.Read (buffer, 0, (int)context.Request.InputStream.Length);
                                                        body = System.Text.UnicodeEncoding.Unicode.GetString (buffer);
                                                }
                                        }
                                        httpMethod = context.Request.HttpMethod;
                                        httpUrl = context.Request.Url.ToString ();
                                        httpQueryString = context.Request.QueryString.ToString ();
                                }
                                foreach ( var item in context.Session ) {
                                        session.Add (item.ToString ());
                                }
                                session2.Add (1);
                                NtvEnterHttp (0xDEADBEEFDEADBEEF, 0x00C0FFEE00C0FFEE, httpMethod, statusCode, substatusCode, httpUrl,
                                       httpQueryString, body, headers.ToArray (), cookies.ToArray (), session.ToArray ());
                        }
                }
                public static void ProcessRequest_Enter (System.Web.HttpWorkerRequest workerRequest, System.Web.HttpContext context) {
                        if ( context != null ) {
                                var something = new List<string> [20,20,20,20,20,20,20,20];
                                List<string> [,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,] testarray;
                                List<List<List<List<string>>>> llllstring = new List<List<List<List<string>>>>();
                                List<string> headers = new List<string> ();
                                List<string> cookies = new List<string> ();
                                List<string> session = new List<string> ();
                                List<int> session2 = new List<int> ();
                                string httpMethod = string.Empty;
                                string httpUrl = string.Empty;
                                string httpQueryString = string.Empty;
                                string body = string.Empty;
                                byte [] buffer = null;
                                int statusCode = 0;
                                int substatusCode = 0;
                                if ( context.Response != null ) {
                                        statusCode = context.Response.StatusCode;
                                        substatusCode = context.Response.SubStatusCode;
                                }
                                if ( context.Request != null ) {
                                        if ( context.Request.Headers != null ) {
                                                foreach ( var item in context.Request.Headers ) {
                                                        headers.Add (item.ToString ());
                                                }
                                        }
                                        if ( context.Request.Cookies != null ) {
                                                foreach ( var item in context.Request.Cookies ) {
                                                        cookies.Add (item.ToString ());
                                                }
                                        }
                                        if ( context.Request.InputStream != null ) {
                                                if ( context.Request.InputStream.Length > 0 ) {
                                                        buffer = new byte [context.Request.InputStream.Length];
                                                        context.Request.InputStream.Read (buffer, 0, (int)context.Request.InputStream.Length);
                                                        body = System.Text.UnicodeEncoding.Unicode.GetString (buffer);
                                                }
                                        }
                                        httpMethod = context.Request.HttpMethod;
                                        httpUrl = context.Request.Url.ToString ();
                                        httpQueryString = context.Request.QueryString.ToString ();
                                }
                                foreach ( var item in context.Session ) {
                                        session.Add (item.ToString ());
                                }
                                session2.Add (1);
                                NtvEnterHttp (0xDEADBEEFDEADBEEF, 0x00C0FFEE00C0FFEE, httpMethod, statusCode, substatusCode, httpUrl,
                                       httpQueryString, body, headers.ToArray (), cookies.ToArray (), session.ToArray ());
                        }
                }
                public static void ProcessRequest_Exit (System.Web.HttpWorkerRequest workerRequest, System.Web.HttpContext context, string [] responseheaders, string [] responseservervars) {
                        string s = "s2";
                        string s2 = "s3";
                        string s3 = "s";
                }
        }
}
