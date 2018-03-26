using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace CSharpImportDemo
{
    class Program
    {
        [DllImport("DllCoreDemo.dll", EntryPoint = "load_image_source")]
        public static extern IntPtr LoadImage(string filename);

        [DllImport("DllCoreDemo.dll", EntryPoint = "extract_image_info")]
        public static extern IntPtr ExtractImgInfo(out int width, out int height, out int channel);

        [DllImport("DllCoreDemo.dll", EntryPoint = "display_image")]
        public static extern IntPtr DisplayImage();

        [DllImport("DllCoreDemo.dll", EntryPoint = "release")]
        public static extern IntPtr Release();

        [DllImport("DllCoreDemo.dll", EntryPoint = "update_struct")]
        public static extern void UpdateStruct(IntPtr frame, ref FrameInfo structure);

        [StructLayout(LayoutKind.Sequential)]
        public struct FrameInfo
        {
            public int width;
            public int height;
            public int channels;
            public long size;
        };

        static void Main(string[] args)
        {
            IntPtr frameMat = LoadImage("test.jpg");

            //int width, height, channels;
            //ExtractImgInfo(out width, out height, out channels);

            FrameInfo info = new FrameInfo();
            UpdateStruct(frameMat, ref info);

            Console.WriteLine("{0} {1} {2} {3}", info.width, info.height, info.channels, info.size);

            DisplayImage();

            Release();
        }
    }
}