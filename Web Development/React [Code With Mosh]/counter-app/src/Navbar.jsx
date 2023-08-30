import React from "react";

const Navbar = ({total}) => {
  return (
    <header>
      <div className="container mx-auto flex flex-wrap p-4 flex-col md:flex-row items-center">
        <h1 className="flex text-xl text-gray-700 font-bold items-center mb-4 md:mb-0" id="Counter-h1">
          Counter{" "}
          <span className="ml-2 mt-6 text-sm text-white bg-orange-600 p-1 px-2 rounded-full">
            {total}
          </span>
        </h1>
      </div>
    </header>
  );
}

export default Navbar;
