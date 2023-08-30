import "./globals.css";
import type { Metadata } from "next";
import Navbar from "./components/Navbar";
import MyProfile from "./components/MyProfile";

export const metadata: Metadata = {
  title: "Natasha Romanoff",
  description: "Building immersive web-apps",
};

export default function RootLayout({
  children,
}: {
  children: React.ReactNode;
}) {
  return (
    <html lang="en">
      <body className="dark:bg-slate-800 ">
        <Navbar />
        <MyProfile />
        {children}
      </body>
    </html>
  );
}
