import React from "react";

var count = 20

function getCount() {
    return (count == 0) ? "Zero" : count;
}

function Counter() {
  return (
    <div className="justify-center w-fit">
      <h2 className=" border-spacing-3 rounded-md border-red-700">{getCount()}</h2>
      <button className="bg-red-600 text-white">Increase</button>
    </div>
  );
}

export default Counter;
