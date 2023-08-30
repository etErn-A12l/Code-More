import React from "react";
import Image from "next/image";

function MyProfile() {
  return (
    <section className="mx-auto w-full mt-4">
      <Image
        className="mx-auto rounded-full border-2 border-slate-700"
        src="/images/black-widow.jpg"
        height={150}
        width={150}
        alt="Natasha Romanoff"
        priority={true}
      />
    </section>
  );
}

export default MyProfile;
