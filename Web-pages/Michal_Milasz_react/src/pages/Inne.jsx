import Menu from "../components/Menu";

export default function Inne() {
  return (
    <>
      <Menu />
      <main className="inne">
        <p>
          Jeżeli masz jakikolwiek problem prawny, skontaktuj się ze mną
          telefonicznie lub umów się na wizytę zgodnie z poniższymi wskazówkami:
        </p>
        <ol>
          <li>
            Wyślij maila na adres michal.milasz@adwokatura.pl, w którym opiszesz
            problem, dołączysz dokumenty, które chcesz abym przeanalizował i
            podasz dogodny dla siebie termin rozmowy.
          </li>
          <li>
            W odpowiedzi prześlę szczegóły dotyczące rozmowy wraz z ceną za
            konsultację, która na pewno nie ulegnie zmianie.
          </li>
          <li>
            Jeśli zaakceptujesz warunki, ja ruszam do pracy! Na podstawie
            otrzymanych od Ciebie informacji i dokumentów przygotowuję się do
            rozmowy tak, aby w trakcie spotkania rozmawiać o samych konkretach!
          </li>
          <li>
            Podczas naszej rozmowy przedstawię sytuację prawną, odpowiem na
            Twoje pytania oraz udzielę Ci informacji jakie dalsze kroki możesz
            podjąć (samodzielnie, z moją pomocą lub z pomocą osób, z którymi
            współpracuję);
          </li>
          <li>Masz problem z głowy!</li>
        </ol>
      </main>
    </>
  );
}
