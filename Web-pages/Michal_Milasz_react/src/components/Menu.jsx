import Tiles from "./Tiles";
import Header from "./Header";
import { useEffect, useRef } from "react";

export default function Menu() {
  const spaceRef = useRef(null);

  useEffect(() => {
    // Przewijanie do elementu <main> po zamontowaniu komponentu
    if (spaceRef.current) {
      spaceRef.current.scrollIntoView({ behavior: "smooth" });
    }
  }, []);
  return (
    <>
      <Header />
      <Tiles />
      <div ref={spaceRef} className="space"></div>
    </>
  );
}
