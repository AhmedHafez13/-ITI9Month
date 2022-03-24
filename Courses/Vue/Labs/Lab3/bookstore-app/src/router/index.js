import { createRouter, createWebHistory } from "vue-router";
import BooksApp from "../components/BooksCards.vue";
import Wishlist from "../components/WishlistTable.vue";

const routes = [
  {
    path: "/",
    name: "books",
    component: BooksApp,
    props: true,
  },
  {
    path: "/wishlist",
    name: "wishlist",
    component: Wishlist,
    props: true,
  },
];

const router = createRouter({
  history: createWebHistory(process.env.BASE_URL),
  routes,
});

export default router;
