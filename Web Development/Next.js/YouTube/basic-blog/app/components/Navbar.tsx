import Link from "next/link";
import React from "react";
import { FaYoutube, FaGithub, FaLaptop } from "react-icons/fa";
function Navbar() {
  return (
    <nav className="bg-black bg-opacity-60 p-2 static top-0 z-10">
      <div className="prose prose-xl mx-auto flex justify-between flex-col sm:flex-row">
        <h1 className="text-lg grid place-content-center mb-2">
          <Link
            href="/"
            className="text-white/70 no-underline hover:text-white"
          >
            Home
          </Link>
        </h1>
        <div className="flex flex-row justify-center gap-4 align-middle sm:justify-evenly">
          <Link
            className="text-white/70 no-underline hover:text-white"
            href="https://youtube.com"
          >
            <FaYoutube />
          </Link>
          <Link
            className="text-white/70 no-underline hover:text-white"
            href="https://youtube.com"
          >
            <FaGithub />
          </Link>
          <Link
            className="text-white/70 no-underline hover:text-white"
            href="https://youtube.com"
          >
            <FaLaptop />
          </Link>
        </div>
      </div>
    </nav>
  );
}

export default Navbar;
