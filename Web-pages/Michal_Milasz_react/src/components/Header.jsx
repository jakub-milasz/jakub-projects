export default function Header() {
  return (
    <header>
      <div className="address">
        <h2>Kontakt</h2>
        <ul>
          <li>tel.: 783 273 664</li>
          <li>e-mail: michal.milasz@adwokatura.pl</li>
          <li>NIP: 8692008386</li>
        </ul>
      </div>
      <div className="full-name">
        <h1>Michał</h1>
        <h1 className="surname">Milasz</h1>
      </div>
      <nav className="buttons">
        <a className="button" href="home">
          Strona główna
        </a>
        <a className="button" href="o-mnie">
          O mnie
        </a>
      </nav>
    </header>
  );
}
