import React, { useState } from "react";

function Counter() {
  const [count, setCount] = useState(0);

  var lists = ["a", "b", "c", "d", "e", "f"];

  function getCount() {
    return count === 0 ? "Zero" : count;
  }

  function getCountClass() {
    let cl = "text-white py-2 mr-4 rounded-lg";
    if (count !== 0) {
      cl += " bg-blue-500 px-7";
    } else {
      cl += " bg-yellow-400 px-4";
    }
    return cl;
  }

  return (
    <div>
      <div className="flex mb-4 my-4 mx-4">
        <h2 className={getCountClass()}>{getCount()}</h2>
        <button
          onClick={() => setCount(count + 1)}
          className="bg-green-600 hover:bg-green-700 text-white py-2 px-4 mx-2 rounded-lg"
        >
          +
        </button>
        <button
          disabled={count === 0}
          onClick={() => setCount(count - 1)}
          className="bg-red-600 hover:bg-red-700 disabled:bg-gray-400 text-white py-2 px-4 rounded-lg"
        >
          -
        </button>
      </div>
      <ul className="mx-4">
        {lists.map((list, index) => (
          <li key={index}>{list}</li>
        ))}
      </ul>
    </div>
  );
}

export default Counter;
